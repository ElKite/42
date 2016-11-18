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

void readAvmFile(std::string s, bool StopOnError)
{
	Parser * parser = new Parser();
	parser->setStopOnError(StopOnError);
	parser->readfile(s);
}

int main(int argc, char **argv)
{
	if (argc == 3) {
		if (strcmp(argv[1],"-d") == 0)
			readAvmFile(argv[2], false);
	}
	else if (argc == 2)
		readAvmFile(argv[1], true);
	else if (argc == 1) {
		std::ofstream logFile;
		logFile.open("Log.txt", std::ofstream::out | std::ofstream::trunc);
		std::string line;
		while (std::getline(std::cin, line)) {
			if (line == ";;")
				break;
			logFile << line + "\n" ;
		}
		logFile.close();
		readAvmFile("Log.txt", true);
	}
	return 0;
}
