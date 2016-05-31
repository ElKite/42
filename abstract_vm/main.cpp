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

#include "Parser.cpp"

#include <iostream>

int main()
{
	Parser * parser = new Parser();
	parser->readfile("example.txt");
}
