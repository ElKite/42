// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Instructions.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/18 15:36:51 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/18 15:36:52 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include "TOperand.hpp"
#include "OperandFactory.hpp"
#include "eOperandType.hpp"
#include <boost/assign/list_of.hpp>
#include <iostream>
#include <vector>

#define INSTRUCTIONS_COUNT 11

static std::string instructions_list[] = {
	"push",
	"pop",
	"dump",
	"assert",
	"add",
	"sub",
	"mul",
	"div",
	"mod",
	"print",
	"exit"};

class Instructions {

	std::vector <const IOperand *> 	stack;
	OperandFactory *				factory;
	bool							_StopOnError;

public:

	Instructions();
	Instructions(Instructions  const & Instructions);
	~Instructions();

	void pop();
	void dump();
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();
	void exit();

	void push(eOperandType type, std::string value) ;
	void assertt(eOperandType type, std::string value) ;

	Instructions & operator=(Instructions const & src);

	void setStopOnError(bool stop);

};

#endif