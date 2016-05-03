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
	return *this;
}

OperandFactory::~OperandFactory()
{
	return ;
}

/*OperandFactory & OperandFactory::operator=(OperandFactory & const src)
{

}*/

IOperand const * OperandFactory::createIOperand(eOperandType type, std::string const & value) const
{
	IOperand * operand = NULL;

	switch(type)
	{
		case INT8:
		{
			operand = createInt8(value);
			break;
		}
		case INT16:
		{
			operand = createInt16(value);
			break ;
		}
		case INT32:
		{
			operand = createInt32(value);
			break;
		}
		case FLOAT:
		{
			operand = createFloat(value);
			break;
		}
		case DOUBLE:
		{
			operand = createDouble(value);
			break;
		}
	}
	return operand;

}

IOperand const * createInt8( std::string const & value ) const
{
	double myValue;
    try {
        myValue = boost::lexical_cast<double>(value);
    } catch(bad_lexical_cast&) {

    }
	TOperand<int8_t>(myValue, INT8); 
}

IOperand const * createInt16( std::string const & value ) const
{
	double myValue;
    try {
        myValue = boost::lexical_cast<double>(value);
    } catch(bad_lexical_cast&) {

    }
	TOperand<int16_t>(myValue, INT16); 
}

IOperand const * createInt32( std::string const & value ) const
{
	double myValue;
    try {
        myValue = boost::lexical_cast<double>(value);
    } catch(bad_lexical_cast&) {

    }
	TOperand<int32_t>(myValue, INT32); 
}

IOperand const * createFloat( std::string const & value ) const
{
	double myValue;
    try {
        myValue = boost::lexical_cast<double>(value);
    } catch(bad_lexical_cast&) {

    }
	TOperand<float>(myValue, FLOAT); 
}

IOperand const * createDouble( std::string const & value ) const
{
	double myValue;
    try {
        myValue = boost::lexical_cast<double>(value);
    } catch(bad_lexical_cast&) {

    }
	TOperand<double>(myValue, DOUBLE); 
}
