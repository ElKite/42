// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Instructions.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/18 15:36:43 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/18 15:36:44 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Instructions.hpp"
#include <boost/lexical_cast.hpp>


Instructions::Instructions()
{
	factory = new OperandFactory();
	return ;
}

Instructions::Instructions(Instructions const & src)
{
	*this = src;
	return ;
}

Instructions::~Instructions()
{
	return ;
}

Instructions &  Instructions::operator=(Instructions const & src)
{
	(void) src;
	return *this;
}

void Instructions::pop() 
{
	//	std::cout << "pop" << std::endl;
	if (stack.size() >= 1) {
		stack.pop_back();
	}
	else
		throw InstructionException("Not enough values on the stack to execute 'pop' instruction");
}

void Instructions::dump()  
{
	//std::cout << "dump" << std::endl;
	for (int i = stack.size() - 1; i >= 0; i--)
	{
		std::cout << stack[i]->toString() << std::endl;
	}
}

void Instructions::add() 
{
	//std::cout << "add" << std::endl;
	if (stack.size() >= 2)
	{
		//std::cout << (*stack[stack.size() - 2]).toString() <<  " + " << (*stack[stack.size() - 1]).toString() << std::endl; 
		stack[stack.size() - 2] = *stack[stack.size() - 1] + *stack[stack.size() -2];
		stack.pop_back();
	} else
		throw InstructionException("Not enough values on the stack to execute 'add' instruction");

}

void Instructions::sub() 
{
	//std::cout << "sub" << std::endl;
	if (stack.size() >= 2)
	{
		//std::cout << (*stack[stack.size() - 2]).toString() <<  " - " << (*stack[stack.size() - 1]).toString() << std::endl; 
		stack[stack.size() - 2] = *stack[stack.size() - 1] - *stack[stack.size() - 2];
		stack.pop_back();
	} else
		throw InstructionException("Not enough values on the stack to execute 'sub' instruction");
}

void Instructions::mul()  
{
	//std::cout << "mul" << std::endl;
	if (stack.size() >= 2)
	{
		//std::cout << (*stack[stack.size() - 2]).toString() <<  " * " << (*stack[stack.size() - 1]).toString() << std::endl; 
		stack[stack.size() - 2] = *stack[stack.size() - 1] * *stack[stack.size() - 2];
		stack.pop_back();
	} else
		throw InstructionException("Not enough values on the stack to execute 'mul' instruction");
}

void Instructions::div() 
{
	//std::cout << "div" << std::endl;
	if (stack.size() >= 2)
	{
		//std::cout << (*stack[stack.size() - 2]).toString() <<  " / " << (*stack[stack.size() - 1]).toString() << std::endl; 
		try {
			stack[stack.size() - 2] = *stack[stack.size() - 1] / *stack[stack.size() - 2];
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
			::exit(1);
		}	
		stack.pop_back();
	} else
		throw InstructionException("Not enough values on the stack to execute 'div' instruction");
}

 void Instructions::mod() 
{
	//std::cout << "mod" << std::endl;
	if (stack.size() >= 2)
	{
		//std::cout << (*stack[stack.size() - 2]).toString() <<  " % " << (*stack[stack.size() - 1]).toString() << std::endl; 
		try {
			stack[stack.size() - 2] = *stack[stack.size() - 1] % *stack[stack.size() - 2];
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
			::exit(1);
		}
		stack.pop_back();
	} 
	else
		throw InstructionException("Not enough values on the stack to execute 'mod' instruction");
}

void Instructions::print() 
{
	//std::cout << "print" << std::endl;
	if (stack.size() >= 1) {
		if (stack.back()->getType() == INT8)
			std::cout << static_cast<char> (stack[stack.size() - 1]->getValue()) << std::endl;
		else
			throw InstructionException("Assert value not true while executing 'print' instruction");
	} else
		throw InstructionException("Not enough values on the stack to execute 'print' instruction");
}

void Instructions::exit() 
{
	//std::cout << "exit" << std::endl;
	::exit(1);
}

void Instructions::push(eOperandType type, std::string value) 
{
	IOperand const * operand = factory->createOperand(type, value);
	//std::cout << std::to_string(operand->getValue()) << std::endl;
	stack.push_back(operand);
}

void Instructions::assertt(eOperandType type, std::string value) 
{
	//std::cout << "assert " << value << std::endl;
	if (stack.size() >= 1) {
		const IOperand * operand = factory->createOperand(type, value);		
		if (stack[stack.size() - 1]->getValue() != operand->getValue() || stack[stack.size() - 1]->getType() != operand->getType()) {
			throw InstructionException("Assert value not true : type or value not equal"); 
		}
	} else
		throw InstructionException("Not enough value on the stack to execute 'assert' instruction");
} 