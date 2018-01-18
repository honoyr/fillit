# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgonor <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 17:11:48 by dgonor            #+#    #+#              #
#    Updated: 2017/12/14 17:11:51 by dgonor           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGSWWW = -Wall -Wextra -Werror

SRC = algorithm.c closestsquare.c create_map.c err.c \
ft_cut.c ft_replacer.c ft_valid.c ft_vfigure.c main_dgonor.c \
ft_strsplit.c ft_putstr.c ft_strnew.c ft_strlen.c ft_strdel.c \
ft_strsub.c ft_putendl.c ft_putchar.c ft_bzero.c ft_memalloc.c \
ft_memdel.c

OB = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	gcc $(FLAGSWWW) -c $(SRC)
	gcc -o $(NAME) $(FLAGSWWW) $(OB) -I.

clean:
	/bin/rm -f $(OB)

fclean: clean
	/bin/rm -f $(NAME)
	
re: fclean all
