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
#include <iostream>
#include "eOperandType.hpp"
#include <cstdint>
#include <string>
#include "MyExceptions.hpp"

typedef struct 	s_operand {
	eOperandType 	type;
	std::string 	name;
	int 			precision;
	long			min;
	long			max;
}				t_operand;

static t_operand myOperand[] = 
{
	{	INT8, "int8", 0,-128, 127 },
	{	INT16, "int16", 1, -32768, 32767 },
	{	INT32, "int32", 2, -2147483648, 2147483647 },
	{	FLOAT, "float", 3, std::numeric_limits<float>::min(), std::numeric_limits<float>::max() },
	{	DOUBLE, "double", 4, std::numeric_limits<double>::min(), std::numeric_limits<double>::max() },
};		

template <typename T> class TOperand : public IOperand {

//class TOperand : public IOperand {

	T 				_value;
	eOperandType 	_type;
	int 			_precision;

public:

	/*Toperand(double value, eOperantType type);
	TOperand(TOperand const & src);
	~TOperand();

	virtual int getPrecision( void ) const; // Precision of the type of the instance
	virtual eOperandType getType( void ) const; // Type of the instance
	T 			getValue();

	IOperand const * createOperator(double value, short preicision);

	TOperand & operator=(Toperand const & src);

	virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo


	virtual std::string const & toString( void ) const; // String representation of the instance*/



TOperand()
{
	return ;
}

TOperand(double value, eOperandType type) : _value(value), _type(type)
{
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
	return std::to_string(this->_value);
}

IOperand const * createOperator(double value, short precision)
{
	TOperand * operand = NULL;

	if (value > myOperand[precision].max)
		throw MathException("Overflow : " + myOperand[precision].name);
	else if (value > myOperand[precision].min)
		throw MathException("Underflow : " + myOperand[precision].name);
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
	TOperand src(static_cast<TOperand>(rhs));
	TOperand * operand = NULL;
	eOperandType type;

	this->_precision >= src.getPrecision() ? type = this->_type : type = src.getType();
	double value = src.getValue() + this->_value;
	operand = createOperator(value, type);
	return operand;
}

IOperand const * operator-(IOperand const & rhs) const
{
	TOperand * operand = NULL;
	TOperand src(static_cast<TOperand>(rhs));
	eOperandType type;

	this->_precision >= src.getPrecision() ? type = this->_type : type = src.getType();
	double value = this->_value - src.getValue();
	operand = createOperator(value, type);
	return operand;
}

IOperand const * operator*(IOperand const & rhs) const
{
	TOperand src(static_cast<TOperand>(rhs));
	TOperand * operand = NULL;
	eOperandType type;

	this->_precision >= src.getPrecision() ? type = this->_type : type = src.getType();
	double value = src.getValue() * this->_value;
	operand = createOperator(value, type);
	return operand;
}

IOperand const * operator/(IOperand const & rhs) const
{
	TOperand * operand = NULL;
	TOperand src(static_cast<TOperand>(rhs));
	eOperandType type;

	this->_precision >= src.getPrecision() ? type = this->_type : type = src.getType();
	if (src.getValue() == 0)
		throw MathException("Division using 0");
	else {
		double value = this->_value / src.getValue();
		operand = createOperator(value, type);
	}
	return operand;
}

IOperand const * operator%(IOperand const & rhs) const
{
	TOperand * operand = NULL;
	TOperand src(static_cast<TOperand>(rhs));
	eOperandType type;

	this->_precision >= src.getPrecision() ? type = this->_type : type = src.getType();
	if (src.getValue() == 0)
		throw MathException("Modulo using 0");
	else {
		double value = this->_value % src.getValue();
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


T getValue()
{
	return this->_value;
}


};

#endif