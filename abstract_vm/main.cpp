// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/03 16:34:17 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/03 16:34:27 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Parser.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFromInput()
{
	std::vector<std::string> input;
	std::string line;

	while (std::getline(std::cin, line)) {
		if (line == ";;") {
			break;
		}
		input.push_back(line);
	}
	Parser * parser = new Parser();
	parser->readFromInput(input);
}

void readAvmFile(std::string s)
{
	Parser * parser = new Parser();
	parser->readfile(s);
}

void readInputAndCreateLog()
{
	std::ofstream logFile;
	logFile.open("Log.txt", std::ofstream::out | std::ofstream::trunc);
	std::string line;
	while (std::getline(std::cin, line)) {
		if (line == ";;")
			break;
		logFile << line + "\n" ;
	}
	logFile.close();
	readAvmFile("Log.txt");
}

int main(int argc, char **argv)
{
	if (argc == 2 && strcmp(argv[1],"-log") == 0) {
		readInputAndCreateLog();
	}
	else if (argc == 2)
		readAvmFile(argv[1]);
	else if (argc == 1) {
		readFromInput();
	}
	return 0;
}
