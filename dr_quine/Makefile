#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 12:56:41 by vtarreau          #+#    #+#              #
#    Updated: 2016/11/23 10:17:16 by vtarreau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAMEA = Colleen
NAMEB = Grace
NAMEC = Sully

COMPILE = clang -Werror -Wall -Wextra -o

GARBAGE = Grace_kid.c \

.PHONY: all clean fclean re proper

all: compile

compile:
	$(COMPILE) $(NAMEA) Colleen.c
	$(COMPILE) $(NAMEB) Grace.c
	$(COMPILE) $(NAMEC) Sully.c

clean:

	rm -rf $(GARBAGE)

fclean: clean
	rm -rf Sully_*
	rm -rf $(NAMEA)
	rm -rf $(NAMEB)
	rm -rf $(NAMEC)

proper: all clean

re: fclean all