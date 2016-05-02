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
#include "TOperand.tpp"
#include <limits>
#include <iostream>
#include "eOperandType"

typedef struct 	s_operand {
	eOperantType 	type;
	std::string 	name;
	int 			precision;
	long			min;
	long			max;
}				t_operand;

static t_operand myOperand[] {
	{
		INT8, "int8", 0,-128, 127
	},
	{
		INT16, "int16", 1, -32768, 32767
	},
	{
		INT32, "int32", 2, -2147483648, 2147483647
	}
	{
		FLOAT, "float", 3,
		std::numeric_limits<float>::min(), std::numeric_limits<float::max()>
	},
	{
		DOUBLE, "double", 4,
		std::numeric_limits<double>::min(), std::numeric_limits<double::max()>
	}
};		

template <typename T> class TOperand;

class TOperand : public IOperand {

	T 				_value;
	eOperantType 	_type;
	int 			_precision;

	TOperand();

public:

	Toperand(double value, eOperantType type);
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


	virtual std::string const & toString( void ) const; // String representation of the instance

};

#endif