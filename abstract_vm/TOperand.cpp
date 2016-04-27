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

template <typename T>
TOperand::TOperand()
{
	return ;
}

template <typename T>
TOperand::TOperand(T value) : _value(value)
{
	return ;
}

template <typename T>
TOperand::TOperand(TOperand const & src)
{
	*this = src;
	return ;
}

template <typename T>
TOperand::~TOperand()
{
	return ;
}


template <typename T>
TOperand & TOperand::operator=(TOperand const &  src)
{
	this->_value = src.getValue();
	return *this;
}

template <typename T>
IOperand const * TOperand::operator+(IOperand const & src) const
{
	
}

template <typename T>
IOperand const * Toperand::operator-(IOperand const & src) const
{

}

template <typename T>
IOperand const * Toperand::operator*(IOperand const & src) const
{

}

template <typename T>
IOperand const * Toperand::operator/(IOperand const & src) const
{

}

template <typename T>
IOperand const * Toperand::operator%(IOperand const & src) const
{

}

template <typename T>
int TOperand::getPrecision(void) const 
{
	return
}

template <typename T>
eOperandType TOperand::getType(void) const
{

}

template <typename T>
T TOperand::getValue()
{

}
