# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:24:36 by ckatelin          #+#    #+#              #
#    Updated: 2019/04/24 15:38:17 by smorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = srcs/main.c srcs/validate.c srcs/store_tetris.c srcs/fillit.c srcs/solve.c srcs/get_next_line/get_next_line.c srcs/get_next_line/libft/libft.a
HEADER = srcs/fillit.h
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -I $(HEADER) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
