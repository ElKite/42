// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/03 16:34:17 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/03 16:34:27 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "TOperand.hpp"
#include "OperandFactory.hpp"
#include "MyExceptions.hpp"

#include <iostream>

int main()
{
	OperandFactory * factory = new OperandFactory();
	IOperand const * a = factory->createOperand(INT32, "3");
	IOperand const * b = factory->createOperand(FLOAT, "127");
	//IOperand const * c = factory->createOperand(FLOAT, "3");

	std::cout << a->getPrecision() <<  " ; " << a->getValue() << " ; " << a->getType() <<std::endl;
	std::cout << b->getPrecision() <<  " ; " << b->getValue() << " ; " << b->getType() <<std::endl;
	IOperand const * c  = *a - *b;
	std::cout << c->getPrecision() <<  " ; " << c->getValue() << " ; " << c->getType() <<std::endl;
	return 0;
}
