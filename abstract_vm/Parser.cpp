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
#include "eOperandType.hpp"
#include <regex>
#include <boost/algorithm/string.hpp>

Parser::Parser()
{
	instructions = new Instructions();
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
	std::ifstream infile(filename);
	std::string line;
	std::vector<std::string> elems;
	int lineNbr = 1;

	while (std::getline(infile, line))
	{
		this->_myLinesNbr = std::to_string(lineNbr);
		try {
 			check_line(line);
 		} catch (const std::exception &e) {
 			std::cout << "Line " << this->_myLinesNbr << ": " << e.what() << std::endl;	
			exit(1);	
 		}
 		lineNbr++;
	}
	if (infile.fail())
		std::cout << "Error: An error occured while reading the file" << std::endl;
	else
		std::cout << "Error: No 'exit' instruction" << std::endl;
}

void Parser::readFromInput(std::vector<std::string> input)
{
	std::string line;
	unsigned long i = 0;

	if (input.size() == 0) {
		std::cout << "Error: No 'exit' instruction" << std::endl;
	} else {
		while (i <= input.size() - 1)
		{
			this->_myLinesNbr = std::to_string(i + 1);
			line = input.at(i); 
			try {
	 			check_line(line);
	 		} catch (const std::exception &e) {
	 			std::cout << "Line " << this->_myLinesNbr << ": " << e.what() << std::endl;	
				exit(1);	
	 		}
	 		i++;
		}
		std::cout << "Error: No 'exit' instruction" << std::endl;
	}
}

void Parser::check_line(std::string line)
{

	std::regex comment("^([ \t]+)?;(.*?)\n?$");
	std::regex empty("^([ \t]+)?\n?$");

	std::regex standard_comment("^(pop|dump|add|sub|mul|div|mod|print|exit)([ \t]+)?;(.*?)\n?$");
	std::regex standard_nocomment("^(pop|dump|add|sub|mul|div|mod|print|exit)([ \t]+)?$");

	std::regex withValue_comment("^((push|assert)[ \t]+(int8\\(|int16\\(|int32\\(|float\\(|double\\()[-+]?[0-9]*\\.?[0-9]+[)])([ \t]+)?(?=;)(.*?)\n?$");
	std::regex withValue_nocomment("^((push|assert)[ \t]+(int8\\(|int16\\(|int32\\(|float\\(|double\\()[-+]?[0-9]*\\.?[0-9]+[)]([ \t]+)?\n?)$");

	if (std::regex_match(line, standard_comment) || std::regex_match(line, standard_nocomment)) {
		check_instructions(line);
	}
	else if (std::regex_match(line, withValue_nocomment)  || std::regex_match(line, withValue_comment))
		check_argumented_instructions(line);
	else if (!std::regex_match(line, comment) && !std::regex_match(line, empty))
	{
		std::string s = "Syntax error";
		throw InstructionException(s);
	}
}

void Parser::check_instructions(std::string line)
{
	for (size_t i = 0; i < INSTRUCTIONS_COUNT; i++) 
	{
		try {
			std::vector<std::string> elems = split(line, ';');
			boost::trim(elems.at(0));

			if (instructions_list[i] == elems.at(0))
			{
				switch (i)
				{
					case 1:
					{	
						instructions->pop();
						break ;
					}
					case 2:
					{	
						instructions->dump();
						break ;
					}
					case 4:
					{
						instructions->add();
						break ;
					}
					case 5:
					{	
						instructions->sub();
						break ;
					}
					case 6:
					{	
						instructions->mul();
						break ;
					}
					case 7:
					{	
						instructions->div();
						break ;
					}
					case 8:
					{	
						instructions->mod();
						break ;
					}
					case 9:
					{	
						instructions->print();
						break ;
					}
					case 10:
					{	
						instructions->exit();
						break ;
					}														
				}
				break ;	
			}
		} catch (const std::exception &e) {
			std::cout << "Line " << this->_myLinesNbr << ": " << e.what() << std::endl;
			exit(1);
		}
	}
}

void Parser::check_argumented_instructions(std::string line)
{
	std::vector<std::string> elems = split(line, ' ');
	std::vector<std::string> type = split(elems.at(1), '(');
	std::vector<std::string> value = split(type.at(1), ')');
	eOperandType myType;

	if (type.at(0) == "int8")
		myType = INT8;
	else if (type.at(0) == "int16")
		myType = INT16;
	else if (type.at(0) == "int32")
		myType = INT32;
	else if (type.at(0) == "double")
		myType = DOUBLE;
	else if (type.at(0) == "float")
		myType = FLOAT;

	if (elems.at(0) == instructions_list[0])
	{
		instructions->push(myType, value.at(0));
	} else if (elems.at(0) == instructions_list[3])
	{
		try {
			instructions->assertt(myType, value.at(0));
		} 
		catch(const std::exception &e) {
			std::cout << "Line " << this->_myLinesNbr << ": " << e.what() << std::endl;
			exit(1);
    	} 
	}
}