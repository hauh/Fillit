/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:08:24 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/22 22:34:56 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line/get_next_line.h"

typedef struct	s_tetris
{
	char			**figure;
	int				rows;
	int				cols;
	struct s_tetris	*next;
}				t_tetris;

void			print_error(void);
int				check_validation(int fd);
t_tetris		*store_tetris(int fd);
int				solve(char **square, t_tetris **list, int y, int x);
char			**fillit(t_tetris **list);

#endif
