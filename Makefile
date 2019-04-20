# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:24:36 by ckatelin          #+#    #+#              #
#    Updated: 2019/04/20 19:31:23 by smorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror 
SRCS = main.c store_tetris.c fillit.c get_next_line/get_next_line.c get_next_line/libft/libft.a
HEADER = fillit.h
NAME = fillit

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRCS) -I $(HEADER) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
