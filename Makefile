# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:24:36 by ckatelin          #+#    #+#              #
#    Updated: 2019/04/24 18:08:23 by ckatelin         ###   ########.fr        #
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
	gcc $(FLAGS) $(SRCS) -I $(HEADER) -L$(LIB) -lft -o $(NAME)

clean:
	make clean -C $(LIB)

fclean: clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re: fclean all
