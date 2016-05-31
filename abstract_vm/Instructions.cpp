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

void Instructions::pop() const
{
	std::cout << "pop" << std::endl;
}

void Instructions::dump() const 
{
	std::cout << "dump" << std::endl;
}

void Instructions::add() const
{
	std::cout << "add" << std::endl;
}

void Instructions::sub() const
{
	std::cout << "sub" << std::endl;
}

void Instructions::mul() const 
{
	std::cout << "mul" << std::endl;
}

void Instructions::div() const
{
	std::cout << "div" << std::endl;
}

 void Instructions::mod() const
{
	std::cout << "mod" << std::endl;
}

void Instructions::print() const
{
	std::cout << "print" << std::endl;
}

void Instructions::exit() const
{
	std::cout << "exit" << std::endl;
}

void Instructions::push(std::string value) const
{
	std::cout << "push " << value << std::endl;
}

void Instructions::assertt(std::string value) const
{
	std::cout << "assert " << value << std::endl;
}