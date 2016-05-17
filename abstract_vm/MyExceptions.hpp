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

class MathException : public std::exception
{

	const char * _error;

	MathException() throw()
	{
		return ;
	}

public:

	MathException(std::string msg) throw()
	{
		this->_error = msg.c_str();
		return ;
	}

	virtual ~MathException() throw()
	{
		return ;
	}

	virtual const char* what() const throw()
    {
    	return _error;
    }

};

class InstructionException : public std::exception
{
	const char * _error;

	InstructionException() throw()
	{
		return ;
	}

public:

	InstructionException(std::string s) throw()
	{
		this->_error = s.c_str();
		return ;
	}

	virtual ~InstructionException() throw()
	{
		return ;
	}

	virtual const char* what() const throw()
    {
    	return _error;
    }

}; 

#endif