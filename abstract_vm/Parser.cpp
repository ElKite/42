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

std::vector<std::string> & Parser::split(const std::string &s, char delim, std::vector<std::string> &elems) 
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
	//check if file or direct input
	Instructions * instructions = new Instructions();
	std::ifstream infile(filename);
	std::string line;
	std::vector<std::string> elems;
	int lineNbr = 0;

	while (std::getline(infile, line))
	{
		std::cout << "LINE " << lineNbr << " : " << line << std::endl;
 		check_line(line, *instructions);
 		lineNbr++;
	}
}

void Parser::check_line(std::string line, Instructions const & instructions)
{
	std::regex standard_comment("((pop)|(dump)|(add)|(sub)|(mul)|(div)|(mod)|(print)|(exit)){1}(?=;)");
	std::regex standard_nocomment("^((pop)|(dump)|(add)|(sub)|(mul)|(div)|(mod)|(print)|(exit)){1}$");

	std::regex withValue_comment("([push|assert]+[ \t]+[int8(|int16|int32(|float(|double(]+-?[0-9]+[)])(?=;)");
	std::regex withValue_nocomment("^([push|assert]+[ \t]+[int8(|int16|int32(|float(|double(]+-?[0-9]+[)])$");

//^(((push)|(assert))+[ \t]+((int8[(])|(int16[(])|(int32[(])|(float[(])|(double[(]))+-?[0-9]+[)])$

	//syntax error
	//instructions unknown
	//type unknown

	if (std::regex_match(line, standard_comment) || std::regex_match(line, standard_nocomment))
		check_instructions(instructions, line);
	//else
		//std::cout << "error matching regex" << std::endl;
		//throw exception
	if (std::regex_match(line, withValue_nocomment)  || std::regex_match(line, withValue_comment))
		check_argumented_instructions(instructions, line);
	//else
		//std::cout << "error matching regex 2" << std::endl;
		//throw exception
}

void Parser::check_instructions(Instructions const & instructions, std::string line)
{
	for (size_t i = 0; i < INSTRUCTIONS_COUNT; i++) 
	{
		//std::cout << "COMPARAISON " << line << " / " << instructions_list[i] << std::endl;
		if (instructions_list[i] == line)
		{
			switch (i)
			{
				case 1:
				{	
					instructions.pop();
					break ;
				}
				case 2:
				{	
					instructions.dump();
					break ;
				}
				case 4:
				{	
					instructions.add();
					break ;
				}
				case 5:
				{	
					instructions.sub();
					break ;
				}
				case 6:
				{	
					instructions.mul();
					break ;
				}
				case 7:
				{	
					instructions.div();
					break ;
				}
				case 8:
				{	
					instructions.mod();
					break ;
				}
				case 9:
				{	
					instructions.print();
					break ;
				}
				case 10:
				{	
					instructions.exit();
					break ;
				}														
			}
			break ;	
		}
	}
}

void Parser::check_argumented_instructions(Instructions const & instructions, std::string line)
{
	std::vector<std::string> elems = split(line, ' ');
//	std::cout << "COMPARAISON" << line << " / " << instructions_list[0] << std::endl;
///	std::cout << "COMPARAISON" << line << " / " << instructions_list[1] << std::endl;
	if (elems.at(0) == instructions_list[0])
	{
		instructions.push(elems.at(1));
	} else if (elems.at(0) == instructions_list[3])
	{
		instructions.assertt(elems.at(1));
	}
}