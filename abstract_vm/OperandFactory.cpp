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

OperandFactory & OperandFactory::operator=(OperandFactory const & src)
{
	(void)src;
	return *this;
}

void  OperandFactory::checkValue(eOperandType type, std::string const & value) const
{
	double d;
    try {
        d = boost::lexical_cast<double>(value);
    } catch(boost::bad_lexical_cast&) {
    	std::cout << "ERROR CAST VALUE STRING TO DOUBLE" << std::endl;
    }
	for (int i = 0; i <= 4 ; i++ )
	{
		if (myOperand[i].type == type)
		{
			if (d > myOperand[i].max) {
				std::string s = "Overflow : " + value + " " + myOperand[i].name;
				throw MathException(s);
			}
			else if (d < myOperand[i].min) {
				std::string s = "Underflow : " + value + " " + myOperand[i].name;
				throw MathException(s);
			}
		}
	}
}

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value) const
{
	try {
		checkValue(type, value);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
		std::exit(1);
	}
	switch(type)
	{
		case INT8:
		{
			//std::cout << "createInt8" <<std::endl;
			return (createInt8(value));
			break;
		}
		case INT16:
		{
			//std::cout << "createInt16" <<std::endl;
			return (createInt16(value));
			break ;
		}
		case INT32:
		{
			//std::cout << "createInt32" <<std::endl;
			return (createInt32(value));
			break;
		}
		case FLOAT:
		{
			//std::cout << "createFloat" <<std::endl;
			return (createFloat(value));
			break;
		}
		case DOUBLE:
		{
			//std::cout << "createDouble" <<std::endl;
			return (createDouble(value));
			break;
		}
	}
}

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	double myValue = 0;
    myValue = boost::lexical_cast<double>(value);
	IOperand * const operand = new TOperand<int8_t>(myValue, INT8);
	return operand;
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	double myValue = 0;
    myValue = boost::lexical_cast<double>(value);
	IOperand * const operand = new TOperand<int16_t>(myValue, INT16);
	return operand;
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	double myValue = 0;
	myValue = boost::lexical_cast<double>(value);
	IOperand * const operand = new TOperand<int32_t>(myValue, INT32);
	return operand;
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	double myValue = 0;
    myValue = boost::lexical_cast<double>(value);
    IOperand * const operand = new TOperand<float>(myValue, FLOAT);
    return operand;
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	double myValue = 0;
    myValue = boost::lexical_cast<double>(value);
 	IOperand * const operand = new TOperand<double>(myValue, DOUBLE);
	return operand;
}
