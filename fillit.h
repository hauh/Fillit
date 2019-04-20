/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 15:08:24 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/19 21:12:33 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line/get_next_line.h"

typedef struct	s_piece
{
	char	fig[4][5];
	int		rows;
	int		cols;
	struct s_piece	*next;
}				t_piece;

typedef	struct	s_position
{
	int x;
	int y;
}		t_position;

void	print_error(void);
int		check_validation(int fd);
t_piece *store_pieces(int fd);
void	fillit(t_piece **list);

#endif
