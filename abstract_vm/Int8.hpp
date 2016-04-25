// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Int8.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/22 14:48:53 by vtarreau          #+#    #+#             //
//   Updated: 2016/04/22 14:48:54 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef IOperand_HPP
#define IOperand_HPP

#include "IOperand.hpp"
#include <stdint.h>

class Int8 : public TOperand, public IOperand {

public:

	virtual int getPrecision( void ) const; // Precision of the type of the instance
	virtual eOperandType getType( void ) const; // Type of the instance

	virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo

	virtual std::string const & toString( void ) const; // String representation of the instance
	virtual ~IOperand( void );

};

#endif
