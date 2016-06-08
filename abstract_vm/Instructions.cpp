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

Instructions::Instructions()
{
	stack = new IOperand[255]
	return ;
}

Instructions::Instructions(Instructions const & src)
{
	*this = src;
	return ;
}

Instructions::~Instructions()
{
	delete [] stack;
	return ;
}

Instructions &  Instructions::operator=(Instructions const & src)
{
	(void) src;
	return *this;
}

void Instructions::pop() const
{
	std::cout << "pop" << std::endl;
}

void Instructions::dump() const 
{
	std::cout << "dump" << std::endl;
	for (int i = top; i > 0; i--)
	{
		std::cout << stack[top]->toString() << std::endl;
	}
}

void Instructions::add() const
{
	std::cout << "add" << std::endl;
	if (top >= 1)
	{
		stack[top - 1] = stack[top] + stack[top -1];
		top--;
	} else
		throw MathException("Not enough values on the stack to execute 'add' instruction");

}

void Instructions::sub() const
{
	std::cout << "sub" << std::endl;
	if (top >= 1)
	{
		stack[top - 1] = stack[top] - stack[top -1];
		top--;
	} else
		throw MathException("Not enough values on the stack to execute 'sub' instruction");
}

void Instructions::mul() const 
{
	std::cout << "mul" << std::endl;
	if (top >= 1)
	{
		stack[top - 1] = stack[top] * stack[top -1];
		top--;
	} else
		throw MathException("Not enough values on the stack to execute 'mul' instruction");
}

void Instructions::div() const
{
	std::cout << "div" << std::endl;
	if (top >= 1)
	{
		stack[top - 1] = stack[top] / stack[top -1];
		top--;
	} else
		throw MathException("Not enough values on the stack to execute 'div' instruction");
}

 void Instructions::mod() const
{
	std::cout << "mod" << std::endl;
	if (top >= 1)
	{
		stack[top - 1] = stack[top] % stack[top -1];
		top--;
	} 
	else
		throw MathException("Not enough values on the stack to execute 'mod' instruction");
}

void Instructions::print() const
{
	std::cout << "print" << std::endl;
	if (stack[top]->getType == INT8)
		std::cout << stack[top]->toString() << std::endl;
	else
		throw MathException("Assert value not true while executing 'print' instruction: " + boost::lexical_cast<std::string>(value));
}

void Instructions::exit() const
{
	std::cout << "exit" << std::endl;
}

void Instructions::push(eOperandType type, std::string value) const
{
	OperandFactory * factory = new OperandFactory();
	stack[top] = factory->createOperand(type, value);
	top++;
}

void Instructions::assertt(eOperandType type, std::string value) const
{
	std::cout << "assert " << value << std::endl;
	if (!(stack[top] == factory->createOperand(type, value)))
		throw MathException("Assert value not true : " + boost::lexical_cast<std::string>(value));
} 