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

void readAvmFile(std::string s)
{
	Parser * parser = new Parser();
	parser->readfile(s);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		readAvmFile(argv[1]);
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
		readAvmFile("Log.txt");
	}
	return 0;
}
