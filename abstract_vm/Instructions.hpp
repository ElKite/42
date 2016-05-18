// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Instructions.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2016/05/18 15:36:51 by vtarreau          #+#    #+#             //
//   Updated: 2016/05/18 15:36:52 by vtarreau         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef INSTRUCTIONS_HPP
#define INSTRUCTIONS_HPP

#include "TOperand.hpp"

class Instructions {



public:

	Instructions();
	Instructions(Instructions const & Instructions);
	~Instructions();

	Instructions & operator=(Instructions & const src);


};

#endif