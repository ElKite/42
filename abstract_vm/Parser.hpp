// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Parser.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/19 15:53:42 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/19 15:53:43 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PARSER_HPP
#define PARSER_HPP

#include "Instructions.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Parser {

	Instructions * instructions;
	std::string _myLinesNbr;

public:

	Parser();
	Parser(Parser const & src);
	~Parser();



	void readfile(std::string filename);
	void readFromInput(std::vector<std::string> input);
	void check_instructions(std::string line);
	void check_argumented_instructions(std::string line);
	void check_line(std::string line);
	std::vector<std::string> split(const std::string & s, char delim);
	std::vector<std::string> &split(const std::string & s, char delim, std::vector<std::string> &elems);
	Parser & operator=(Parser const & src);

};

#endif