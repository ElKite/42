// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TOperand.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/22 14:41:37 by vtarreau          #+#    #+#             //
//   Updated: 2016/04/22 14:41:38 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef TOPERAND_HPP
#define TOPERAND_HPP

#include "IOperand.hpp"
#include <limits>
#include <math.h>
#include <iostream>
#include "eOperandType.hpp"
#include <cstdint>
#include <string>
#include <boost/lexical_cast.hpp>
#include "MyExceptions.hpp"

typedef struct 	s_operand {
	eOperandType 	type;
	std::string 	name;
	int 			precision;
	long double			min;
	long double			max;
}				t_operand;

static t_operand myOperand[] = 
{
	{	INT8, "int8", 0,-128, 127 },
	{	INT16, "int16", 1, -32768, 32767 },
	{	INT32, "int32", 2, -2147483648, 2147483647 },
	{	FLOAT, "float", 3, std::numeric_limits<float>::lowest(), std::numeric_limits<float>::max()},
	{	DOUBLE, "double", 4, std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max() },
};		

template <typename T> class TOperand : public IOperand {

	T 				_value;
	eOperandType 	_type;
	int 			_precision;

public:

	TOperand() 
	{
		return ;
	}

	TOperand(double value, eOperandType type) : _value(value), _type(type)
	{
		for (int i = 0; i <= 4; i++)
		{
			if (myOperand[i].type == this->_type)
			{
				this->_precision = myOperand[i].precision;
				break ;
			}
		}
		return ;
	}

	TOperand(TOperand<T> const & src)
	{
		*this = src;
		return *this;
	}

	~TOperand()
	{
		return ;
	}

	TOperand<T> & operator=(TOperand<T> const &  src)
	{
		this->_value = src.getValue();
		this->_precision = src.getPrecision();
		this->_type = src.getType();
		return *this;
	}

	std::string const & toString() const
	{
		//std::ostringstream sstream;
		//sstream << this->_value;
		//std::string * s = new std::string(sstream.str());
		//std::cout << " TEST " + sstream.str() << std::endl;
		std::string * s = new std::string(std::to_string(this->_value));
		return *s;
	}

	IOperand * createOperator(double value, short precision) const
	{
		IOperand * operand = NULL;
		if (value > myOperand[precision].max)
			throw MathException("Overflow : " + boost::lexical_cast<std::string>(value) + " " +  myOperand[precision].name);
		else if (value < myOperand[precision].min)
			throw MathException("Underflow : " + boost::lexical_cast<std::string>(value) + " " + myOperand[precision].name);
		switch(precision)
		{
			case 0:
			{
				eOperandType myEnum = INT8;
				operand = new TOperand<int8_t>(value, myEnum);
				break;
			}
			case 1:
			{
				eOperandType myEnum = INT16;
				operand = new TOperand<int16_t>(value, myEnum);
				break ;
			}
			case 2:
			{
				eOperandType myEnum = INT32;
				operand = new TOperand<int32_t>(value, myEnum);
				break;
			}
			case 3:
			{
				eOperandType myEnum = FLOAT;
				operand = new TOperand<float>(value, myEnum);
				break;
			}
			case 4:
			{
				eOperandType myEnum = DOUBLE;
				operand = new TOperand<double>(value, myEnum);
				break;
			}
		}
		return operand;
	}

	IOperand const * operator+(IOperand const & rhs) const
	{
		eOperandType type;

		this->_precision >= rhs.getPrecision() ? type = this->_type : type = rhs.getType();
		double value = rhs.getValue() + this->_value;
		IOperand * operand = createOperator(value, type);
		return operand;
	}

	IOperand const * operator-(IOperand const & rhs) const
	{
		eOperandType type;

		this->_precision >= rhs.getPrecision() ? type = this->_type : type = rhs.getType();
		double value = this->_value - rhs.getValue();
		IOperand * operand = createOperator(value, type);
		return operand;
	}

	IOperand const * operator*(IOperand const & rhs) const
	{
		eOperandType type;

		this->_precision >= rhs.getPrecision() ? type = this->_type : type = rhs.getType();
		double value = rhs.getValue() * this->_value;
		IOperand * operand = createOperator(value, type);
		return operand;
	}

	IOperand const * operator/(IOperand const & rhs) const
	{
		IOperand * operand;
		eOperandType type;

		this->_precision >= rhs.getPrecision() ? type = this->_type : type = rhs.getType();
		if (rhs.getValue() == 0 || this->_value == 0){
			std::string s = "Division using 0";
			throw MathException(s);
		}
		else {
			double value = this->_value / rhs.getValue();
			operand = createOperator(value, type);
		}
		return operand;
	}

	IOperand const * operator%(IOperand const & rhs) const
	{
		IOperand * operand;
		eOperandType type;

		this->_precision >= rhs.getPrecision() ? type = this->_type : type = rhs.getType();
		if (rhs.getValue() == 0)
			throw MathException("Modulo using 0");
		else {
			double value = fmod(this->_value,rhs.getValue());
			operand = createOperator(value, type);
		}
		return operand;
	}

	int getPrecision(void) const 
	{
		return this->_precision;
	}

	eOperandType getType(void) const
	{
		return this->_type;
	}


	double getValue() const
	{
		return this->_value;
	}


};

#endif