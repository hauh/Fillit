# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:24:36 by ckatelin          #+#    #+#              #
#    Updated: 2019/04/24 20:34:59 by smorty           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = srcs/main.c srcs/validate.c srcs/store_tetris.c srcs/fillit.c srcs/solve.c srcs/get_next_line/get_next_line.c
HEADER = ./includes/
FLAGS = -Wall -Wextra -Werror
LIB = ./srcs/libft/

all: $(NAME)

$(NAME):
	make -C $(LIB)
	gcc $(FLAGS) $(SRCS) -I $(HEADER) -L$(LIB) -lft -o $(NAME) -g

clean:
	make fclean -C $(LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
