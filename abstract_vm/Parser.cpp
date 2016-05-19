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

Parser::Parser()
{
	return ;
}

Parser::Parser(Parser const & src)
{
	*this = src
	return ;
}

Parrser::~Parser()
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
	std::vecotr<std::string> elems;
	
	split(s, delim, elems);
	return elems;
}

void Parser::readfile(std::string filename)
{
	Instructions * instructions = new Instructions();
	std::string line;

	while (std::getline(src, line))
	{
 		if (line.at(0) == ';')
 			continue ;

	}
}