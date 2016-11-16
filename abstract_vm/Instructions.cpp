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
	//std::cout << "pop" << std::endl;
	stack.pop_back();
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
	if (stack.size() >= 1)
	{
		std::cout << (*stack[stack.size() - 2]).toString() <<  " + " << (*stack[stack.size() - 1]).toString() << std::endl; 
		stack[stack.size() - 2] = *stack[stack.size() - 1] + *stack[stack.size() -2];
		stack.pop_back();
	} else
		throw MathException("Not enough values on the stack to execute 'add' instruction");

}

void Instructions::sub() 
{
	//std::cout << "sub" << std::endl;
	if (stack.size() >= 1)
	{
		std::cout << (*stack[stack.size() - 2]).toString() <<  " - " << (*stack[stack.size() - 1]).toString() << std::endl; 
		stack[stack.size() - 2] = *stack[stack.size() - 1] - *stack[stack.size() - 2];
		stack.pop_back();
	} else
		throw MathException("Not enough values on the stack to execute 'sub' instruction");
}

void Instructions::mul()  
{
	//std::cout << "mul" << std::endl;
	if (stack.size() >= 1)
	{
		std::cout << (*stack[stack.size() - 2]).toString() <<  " * " << (*stack[stack.size() - 1]).toString() << std::endl; 
		stack[stack.size() - 2] = *stack[stack.size() - 1] * *stack[stack.size() - 2];
		stack.pop_back();
	} else
		throw MathException("Not enough values on the stack to execute 'mul' instruction");
}

void Instructions::div() 
{
	//std::cout << "div" << std::endl;
	if (stack.size() >= 1)
	{
		stack[stack.size() - 2] = *stack[stack.size() - 1] / *stack[stack.size() - 2];
	} else
		throw MathException("Not enough values on the stack to execute 'div' instruction");
}

 void Instructions::mod() 
{
	//std::cout << "mod" << std::endl;
	if (stack.size() >= 1)
	{
		stack[stack.size() - 2] = *stack[stack.size() - 1] % *stack[stack.size() - 2];
	} 
	else
		throw MathException("Not enough values on the stack to execute 'mod' instruction");
}

void Instructions::print() 
{
	//std::cout << "print" << std::endl;
	if (stack.back()->getType() == INT8)
		std::cout << stack[stack.size()]->toString() << std::endl;
	else
		throw MathException("Assert value not true while executing 'print' instruction: " + stack.back()->toString());
}

void Instructions::exit() 
{
	std::cout << "exit" << std::endl;
}

void Instructions::push(eOperandType type, std::string value) 
{
	OperandFactory * factory = new OperandFactory();
	stack.push_back(factory->createOperand(type, value));
}

void Instructions::assertt(eOperandType type, std::string value) 
{
	std::cout << "assert " << value << std::endl;
	if (!(stack.back() == factory->createOperand(type, value)))
		throw MathException("Assert value not true : " + value);
} 