// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   TOperand.tpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/27 14:15:01 by vtarreau          #+#    #+#             //
//   Updated: 2016/04/27 14:15:01 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TOperand.hpp"
#include <cstdint.h>

TOperand::TOperand()
{
	return ;
}

TOperand::TOperand(double value, eOperandType type) : _value(value), _type(type)
{
	return ;
}

TOperand::TOperand(TOperand<T> const & src)
{
	*this = src;
	return ;
}

TOperand::~TOperand()
{
	return ;
}


template <typename T>
TOperand<T> & TOperand::operator=(TOperand<T> const &  src)
{
	this->_value = src.getValue();
	this->_precision = src.getPrecision();
	this->_type = src.getType();
	return *this;
}

IOperand const * Toperand::createOperator(double value, short precision)
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
			Operand myEnum = INT8;
			operand = new TOperand<int8_t>(value, myEnum);
			break;
		}
		case 1:
		{
			Operand myEnum = INT16;
			operand = new TOperand<int16_t)>(value, myEnum);
			break ;
		}
		case 2:
		{
			Operand myEnum = INT32;
			operand = new TOperand<int32_t>(value, myEnum);
			break;
		}
		case 3:
		{
			Operand myEnum = FLOAT;
			operand = new TOperand<float>(value, myEnum);
			break;
		}
		case 4:
		{
			Operand myEnum = DOUBLE;
			operand = new TOperand<double>(value, myEnum);
			break;
		}
	}
	return operand;
}

IOperand const * TOperand::operator+(IOperand const & src) const
{
	TOperand * operand = NULL;
	this->_precision >= src.getPrecision() ? type = this->_type ? type = src.getType();
	double value = src.getValue + this->_value;
	operand = createOperator(value, myOperand[type].precision);
	return operand;
}

IOperand const * Toperand::operator-(IOperand const & src) const
{
	TOperand * operand = NULL;
	this->_precision >= src.getPrecision() ? type = this->_type ? type = src.getType();
	double value = this->_value - src.getValue();
	operand = createOperator(value, myOperand[type].precision);
	return operand;
}

IOperand const * Toperand::operator*(IOperand const & src) const
{
	TOperand * operand = NULL;
	this->_precision >= src.getPrecision() ? type = this->_type ? type = src.getType();
	double value = src.getValue * this->_value;
	operand = createOperator(value, myOperand[type].precision);
	return operand;
}

IOperand const * Toperand::operator/(IOperand const & src) const
{
	TOperand * operand = NULL;
	this->_precision >= src.getPrecision() ? type = this->_type ? type = src.getType();
	if (src.getValue() == 0)
		throw MathException("Division using 0");
	else {
		double value = this->_value / src.getValue();
		operand = createOperator(value, myOperand[type].precision);
	}
	return operand;
}

IOperand const * Toperand::operator%(IOperand const & src) const
{
	TOperand * operand = NULL;
	this->_precision >= src.getPrecision() ? type = this->_type ? type = src.getType();
	if (src.getValue() == 0)
		throw MathException("Modulo using 0");
	else {
		double value = this->_value % src.getValue();
		operand = createOperator(value, myOperand[type].precision);
	}
	return operand;
}

int TOperand::getPrecision(void) const 
{
	return this->_precision;
}

template <typename T>
eOperandType TOperand::getType(void) const
{
	return this->_type;
}

template <typename T>
T TOperand::getValue()
{
	return this->_value;
}
