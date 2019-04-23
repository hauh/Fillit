/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:08:24 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/23 21:14:59 by smorty           ###   ########.fr       */
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

void			error(void);
void			validate(char *file);
t_tetris		*store_tetris(int fd);
char			**fillit(t_tetris **list);
void			free_square(char **square, int i);
int				solve(char **square, t_tetris **list, int y, int x);

#endif
