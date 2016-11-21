// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   MyExceptions.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/02 14:20:44 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/02 14:20:44 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MYEXCEPTIONS_HPP
#define MYEXCEPTIONS_HPP

#include <iostream>
#include <exception>
#include <string>

class MathException : public std::exception
{

	std::string _error;

	MathException() throw()
	{
		return ;
	}

public:

	MathException(std::string msg) throw()
	{
		this->_error = "MathException: " + msg;
		return ;
	}

	virtual ~MathException() throw()
	{
		return ;
	}

	virtual const char* what() const throw()
    {
    	return _error.c_str();
    }

};

class InstructionException : public std::exception
{
	std::string _error;

	InstructionException() throw()
	{
		return ;
	}

public:

	InstructionException(std::string s) throw()
	{
		this->_error = "InstructionException: " + s;
		return ;
	}

	virtual ~InstructionException() throw()
	{
		return ;
	}

	virtual const char* what() const throw()
    {
    	return _error.c_str();
    }

}; 

#endif