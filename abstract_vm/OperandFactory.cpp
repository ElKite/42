// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OperandFactory.cpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 14:28:40 by vtarreau          #+#    #+#             //
//   Updated: 2016/04/26 14:28:41 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "OperandFactory.hpp"
#include <boost/lexical_cast.hpp>
#include "MyExceptions.hpp"

OperandFactory::OperandFactory() 
{
	return ;
}

OperandFactory::OperandFactory(OperandFactory const & src)
{
	*this = src;
	return ;
}

OperandFactory::~OperandFactory()
{
	return ;
}

/*OperandFactory & OperandFactory::operator=(OperandFactory & const src)
{

}*/

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	switch(type)
	{
		case INT8:
		{
			return (createInt8(value));
			break;
		}
		case INT16:
		{
			return (createInt16(value));
			break ;
		}
		case INT32:
		{
			return (createInt32(value));
			break;
		}
		case FLOAT:
		{
			return (createFloat(value));
			break;
		}
		case DOUBLE:
		{
			return (createDouble(value));
			break;
		}
	}
}

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	double myValue = 0;
    try {
        myValue = boost::lexical_cast<int8_t>(value);
    } catch(boost::bad_lexical_cast&) {

    }
	IOperand * const operand = new TOperand<int8_t>(myValue, INT8);
	return operand;
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	double myValue = 0;
    try {
        myValue = boost::lexical_cast<int16_t>(value);
    } catch(boost::bad_lexical_cast&) {

    }
	IOperand * const operand = new TOperand<int16_t>(myValue, INT16);
	return operand;
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	double myValue = 0;
    try {
        myValue = boost::lexical_cast<int32_t>(value);
    } catch(boost::bad_lexical_cast&) {

    }
	IOperand * const operand = new TOperand<int32_t>(myValue, INT32);
	return operand;
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	double myValue = 0;
    try {
        myValue = boost::lexical_cast<float>(value);
    } catch(boost::bad_lexical_cast&) {

    }
    IOperand * const operand = new TOperand<float>(myValue, FLOAT);
    return operand;
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	double myValue = 0;
    try {
        myValue = boost::lexical_cast<double>(value);
    } catch(boost::bad_lexical_cast&) {

    }
	IOperand * const operand = new TOperand<double>(myValue, DOUBLE);
	return operand;
}
