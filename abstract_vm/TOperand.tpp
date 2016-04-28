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

IOperand const * TOperand::operator+(IOperand const & src) const
{
	TOperand * operand = NULL;
	this->_precision >= src.getPrecision() ? type = this->_type ? type = src.getType();

	double value = src.getValue + this->_value;
	//throw exception


	switch(myOperand[type].precision)
	{
		case 0:
		{
			operand = new TOperand<int8_t>(value, INT8);
			break;
		}
		case 1:
		{
			operand = new TOperand<int16_t)>(value, INT16);
			break ;
		}
		case 2:
		{
			operand = new TOperand<int32_t>(value, INT32);
			break;
		}
		case 3:
		{
			operand = new TOperand<float>(value, FLOAT);
			break;
		}
		case 4:
		{
			operand = new TOperand<double>(value, DOUBLE);
			break;
		}
	}
	return operand;
}

IOperand const * Toperand::operator-(IOperand const & src) const
{
	this->_value -= src.getValue();
	return this;
}

IOperand const * Toperand::operator*(IOperand const & src) const
{
	this->_value *= src.getValue();
	return this;
}

IOperand const * Toperand::operator/(IOperand const & src) const
{
	this->_value /= src.getValue();
	return this;
}

IOperand const * Toperand::operator%(IOperand const & src) const
{
	this->_value %= src.getValue();
	return this;
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
