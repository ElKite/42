#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/20 14:17:44 by vtarreau          #+#    #+#              #
#    Updated: 2016/01/13 16:26:43 by vtarreau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC_PATH = ./srcs/
SRC_NAME = 	main.c \
			compute.c \
			lst_util.c \
			parse.c \
			tools.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

INC_PATH = ./libft/includes/ ./includes/

LIB_PATH = ./libft/
LIB_NAME = ./libft/libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_PATH)
		$(CC) $(CFLAGS) $(LIB) $(INC) -o $(NAME) $(LIB_NAME) $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir $(OBJ_PATH) 2> /dev/null || echo "" >/dev/null
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
		rm -fv $(OBJ)
		@make -C $(LIB_PATH) clean
		@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean:
		rm -fv $(OBJ)
		rm -fv $(NAME)
		@make -C $(LIB_PATH) fclean

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH) *.h



