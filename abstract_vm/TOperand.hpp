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

template <typename T> class TOperand;

class TOperand : public IOperand {

	T _value;

	TOperand();

public:

	Toperand(T value){};
	TOperand(TOperand const & src);
	~TOperand();

	virtual int getPrecision( void ) const; // Precision of the type of the instance
	virtual eOperandType getType( void ) const; // Type of the instance
	T 			getValue();

	TOperand & operator=(Toperand const & src);

	virtual IOperand const * operator+( IOperand const & rhs ) const; // Sum
	virtual IOperand const * operator-( IOperand const & rhs ) const; // Difference
	virtual IOperand const * operator*( IOperand const & rhs ) const; // Product
	virtual IOperand const * operator/( IOperand const & rhs ) const; // Quotient
	virtual IOperand const * operator%( IOperand const & rhs ) const; // Modulo

	virtual std::string const & toString( void ) const; // String representation of the instance

};

#endif