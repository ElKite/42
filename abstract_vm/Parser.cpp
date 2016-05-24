// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/19 15:53:51 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/19 15:53:52 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"
#include <regex>

Parser::Parser()
{
	return ;
}

Parser::Parser(Parser const & src)
{
	*this = src;
	return ;
}

Parser::~Parser()
{
	return ;
}

Parser & Parser::operator=(Parser const & src)
{
	(void)src;
	return *this;
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) 
{
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> Parser::split(const std::string & s, char delim)
{
	std::vector<std::string> elems;
	
	split(s, delim, elems);
	return elems;
}

void Parser::readfile(std::string filename)
{

	Instructions * instructions = new Instructions();
	std::ifstream infile(filename);
	std::string line;
	std::vector<std::string> elems;

	while (std::getline(infile, line))
	{
 		check_line(line);
 		check_instructions(*instructions, elems);
	}
}

void Parser::check_line(std::string line)
{
	regex standard = "[pop|dump|add|sub|mul|div|mod|print|exit]";
	regex withValue = "[push|assert]+[ \t]+[int8(|int16|int32(|float(|double(]+-?[0-9]+[)]";

}

void Parser::check_instructions(Instructions const & instructions, std::vector<std::string> elems)
{
	(void) instructions;
	for (size_t i = 0; i < INSTRUCTIONS_COUNT; i++) 
	{
		if (instructions_list[i] == elems.at(0))
			std::cout << elems.at(0) << std::endl;
			//instruction list function
	}
}