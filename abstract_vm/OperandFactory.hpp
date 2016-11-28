// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   OperandFactory.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/04/26 14:28:32 by vtarreau          #+#    #+#             //
//   Updated: 2016/04/26 14:28:33 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include <iostream>
#include "IOperand.hpp"
#include "eOperandType.hpp"
#include "TOperand.hpp"

class OperandFactory {

	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	void  checkValue(eOperandType type, std::string const & value) const;

public:

	OperandFactory();
	OperandFactory(OperandFactory const & src);
	~OperandFactory();

	OperandFactory & operator=(OperandFactory const & src);

	IOperand const * createOperand(eOperandType type, std::string const & value) const;
};

#endif