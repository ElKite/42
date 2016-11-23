#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/04 12:56:41 by vtarreau          #+#    #+#              #
#    Updated: 2016/11/23 08:45:51 by vtarreau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang++
NAME = abstract_vm
CFLAGS = -Wall -Wextra -Werror -I /nfs/2014/v/vtarreau/.brew/include/
OBJDIR = obj/
SRCS = main.cpp \
		OperandFactory.cpp \
		Instructions.cpp \
		Parser.cpp \

OBJS = $(addprefix $(OBJDIR),$(subst .cpp,.o,$(SRCS)))

ABS_FILES = Log.txt

.PHONY: all clean fclean re proper

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDES)

$(OBJS): | $(OBJDIR)

$(OBJDIR)%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then \
		mkdir $(OBJDIR);\
		fi

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJDIR)
	rm -rf $(ABS_FILES)

fclean: clean
	rm -rf $(NAME)

proper: all clean

re: fclean all