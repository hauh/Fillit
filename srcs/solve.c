/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 16:24:01 by smorty            #+#    #+#             */
/*   Updated: 2019/04/24 17:21:46 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_spot(char **square, t_tetris **list, int y, int x)
{
	int i;
	int j;

	i = 0;
	if (x + (*list)->cols <= (int)ft_strlen(square[0]))
	{
		while (i < (*list)->rows)
		{
			j = 0;
			while (j < (*list)->cols)
			{
				if ((square[y + i][x + j] != '.') &&
					((*list)->figure[i][j] != '.'))
					return (0);
				j++;
			}
			i++;
		}
		return (1);
	}
	return (0);
}

static void	add_piece(char **square, t_tetris **list, int y, int x)
{
	int i;
	int j;

	i = 0;
	while (i < (*list)->rows)
	{
		j = 0;
		while (j < (*list)->cols)
		{
			if ((*list)->figure[i][j] != '.')
				square[y + i][x + j] = (*list)->figure[i][j];
			j++;
		}
		i++;
	}
}

static void	remove_piece(char **square, t_tetris **list, int y, int x)
{
	int i;
	int j;

	i = 0;
	while (i < (*list)->rows)
	{
		j = 0;
		while (j < (*list)->cols)
		{
			if ((*list)->figure[i][j] != '.')
				square[y + i][x + j] = '.';
			j++;
		}
		i++;
	}
}

int			solve(char **square, t_tetris **list, int y, int x)
{
	int size;

	size = ft_strlen(square[0]);
	if (*list)
	{
		if (y + (*list)->rows <= size)
		{
			while ((square[y][x] != '\0') && !check_spot(square, list, y, x))
				x++;
			if (check_spot(square, list, y, x))
			{
				add_piece(square, list, y, x);
				if (!solve(square, &(*list)->next, 0, 0))
					return (0);
				else
					remove_piece(square, list, y, x);
			}
			if (x + 1 + (*list)->cols <= size)
				return (solve(square, list, y, x + 1));
		}
		if (y + 1 + (*list)->rows <= size)
			return (solve(square, list, y + 1, 0));
		return (1);
	}
	return (0);
}
