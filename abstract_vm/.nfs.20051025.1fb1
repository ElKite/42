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

	IOperand * stack;
	int top = 0;

public:

	Instructions();
	Instructions(Instructions  const & Instructions);
	~Instructions();

	void pop() const;
	void dump() const;
	void add() const;
	void sub() const ;
	void mul() const;
	void div() const;
	void mod() const;
	void print() const;
	void exit() const;

	void push(std::string value) const;
	void assertt(std::string value) const;

	Instructions & operator=(Instructions const & src);

};

#endif