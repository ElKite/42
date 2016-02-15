#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/11 16:14:33 by vtarreau          #+#    #+#              #
#    Updated: 2015/03/30 14:59:01 by vtarreau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC.C = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_strlcat.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_strfjoin.c \
		ft_isanycapital.c \
		ft_lstlen.c \
		ft_strtoupper.c \
		ft_strtolower.c \
		ft_lstpushback.c \
		ft_lstr.c \
		ft_lstrr.c \
		ft_lstmoveto.c \
		ft_str_onespace.c \
		ft_len_untill.c \
		ft_tablen.c \
		ft_isint.c \
		ft_is_str_digit.c \
		ft_replace_char.c \
		ft_tabcpy.c \
		ft_add_str_to_tab.c \
		ft_char_position.c \
		ft_string_position.c \
		ft_replace_str_in_tab.c \
		ft_del_tab_str.c \
		ft_tabception.c 
SRC.O = $(SRC.C:.c=.o)

INCL = ./includes/libft.h

all:		$(NAME)

$(NAME):	$(SRC.O)
			ar rc $(NAME) $(SRC.O)
			ranlib $(NAME)

clean:		
			/bin/rm -f $(SRC.O)

fclean:		clean
			/bin/rm -f $(NAME)

re:			fclean all

%.o: %.c $(INCL)
	$(CC) $(FLAGS) -I ./includes/ -c $<

.PHONY: all clean fclean re