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
 		check_line(line, *instructions);
	}
}

void Parser::check_line(std::string line, Instructions const & instructions)
{
	regex standard_comment = "((pop)|(dump)|(add)|(sub)|(mul)|(div)|(mod)|(print)|(exit)){1}(?=;)";
	regex standard_nocomment = "^((pop)|(dump)|(add)|(sub)|(mul)|(div)|(mod)|(print)|(exit)){1}$";

	regex withValue_comment = "([push|assert]+[ \t]+[int8(|int16|int32(|float(|double(]+-?[0-9]+[)])(?=;)";
	regex withValue_nocomment = "^([push|assert]+[ \t]+[int8(|int16|int32(|float(|double(]+-?[0-9]+[)])$";

	if (std::regex_match(line, standard_comment) || std::regex_match(line, standard_nocomment))
		check_argumented_instructions(line, instructions);
	else
		//throw exception
	if (std::regex_match(line, withValue_nocomment) || std::regex_match(line, withValue_comment))
		check_instructions(line, instructions);
	else
		//throw exception
}

void Parser::check_instructions(Instructions const & instructions, std::string line)
{
	for (size_t i = 0; i < INSTRUCTIONS_COUNT; i++) 
	{
		if (instructions_list[i] == line)
		{
			switch (i)
			{
				case 0:
				{

					break ;
				}
			}	
		}
	}
}

void Parser::check_argumented_instructions(Instructions const & instructions, std::string line)
{
	
}