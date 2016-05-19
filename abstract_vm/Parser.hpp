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
#include <vector>

class Parser {

public:

	Parser();
	Parser(Parser const & src);
	~Parser();



	void readfile();
	std::vector<std::string> split(const std::string & s, char delim);
	std::vector<std::string> &split(const std::string & s, char delim, std::vector<std::string> &elems);
	Parser & operator=(Parser const & src);

};

#endif