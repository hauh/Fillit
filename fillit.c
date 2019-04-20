/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/20 21:10:33 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int check_spot(char ***square, t_tetris **list)
{
	int x;
	int y;

	if (ft_strlen(**square) >= (*list)->cols)
	{
		y = 0;
		while (y < (*list)->rows)
		{
			x = 0;
			while (x < (*list)->cols)
			{
				if ((*square)[y][x] != '.' && (*list)->figure[y][x] != '.')
					return (1);
				x++;
			}
			y++;
		}
	}
	return (0);
}

static int find_dot(char *line)
{
	char *line0;

	line0 = line;
	while (*line)
	{
		if (*line == '.')
			return (line - line0);
		line++;
	}
	return (0);
}

static int solve(char **square, t_tetris **list, int size)
{
	int i;
	int j;
	int dot;

	if (*list)
	{
		i = 0;
		while (i < size)
		{
			if (!square[i])
				return (1);
			dot = find_dot(square[i]);
			if ((*list)->figure[i])
			{
				if (ft_strlen(square[i]) - dot < ft_strlen((*list)->figure[i]))
				{
					printf("size next\n");
					return (1);
				}
				j = 0;
				while ((*list)->figure[i][j])
				{
					square[i][dot + j] = (*list)->figure[i][j];
					j++;
				}
				printf("%s\n", square[i]);
			}
			else
				break;
			i++;
		}
		printf("add next\n");
		return (solve(square, &(*list)->next, size));
	}
	return (0);
}

static char **create_square(unsigned int size)
{
	char **square;
	unsigned int i;

	square = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size)
	{
		square[i] = (char *)malloc(sizeof(char) * (size + 1));
		ft_memset(square[i], '.', size);
		i++;
	}
	square[size] = NULL;
	printf("square size: %d\n", size);
	return (square);
}

void fillit(t_tetris **list)
{
	unsigned int size;
	char **square;

	size = 4;
	while (size < 20)
	{
		square = create_square(size);
		if (!solve(square, list, size))
			break ;
		size++;
	}
}
