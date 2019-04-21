/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/21 19:26:30 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static void print_solution(char **square)
{
	int i;

	i = 0;
	while (square[i])
	{
		printf("%s\n", square[i]);
		i++;
	}
}

static int check_spot(char **square, t_tetris **list, int y, int x)
{
	int i;
	int j;
	int end;

	end = 0;
	while (square[end])
		end++;
	if ((x + (*list)->cols) <= (int)ft_strlen(square[y]) && (y + (*list)->rows <= end))
	{
		i = 0;
		while (i < (*list)->rows)
		{
			j = 0;
			while (j < (*list)->cols)
			{
				if (square[y + i][x + j] != '.' && (*list)->figure[i][j] != '.')
					return (1);
				j++;
			}
			i++;
		}
	}
	else
		return (1);
	return (0);
}

static void add_piece(char **square, t_tetris **list, int y, int x)
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

static int solve(char **square, t_tetris **list, int size, int y, int x)
{
	if (*list)
	{
		if (y + (*list)->rows <= size)
		{
			if (x + (*list)->cols <= size)
			{
				printf("spot[%d][%d]: %d\n", y, x, check_spot(square, list, y, x));
				if (!check_spot(square, list, y, x))
				{
					add_piece(square, list, y, x);
					print_solution(&*square);
					printf("add next\n");
					return (solve(square, &(*list)->next, size, 0, 0));
				}
				if (x + 1 + (*list)->cols <= size)
					return (solve(square, list, size, y, x + 1));
			}
			if (y + 1 + (*list)->rows <= size)
				return (solve(square, list, size, y + 1, 0));
		}
		return (1);
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
		square[i][size] = '\0';
		i++;
	}
	square[i] = NULL;
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
		if (!solve(square, list, size, 0, 0))
			break ;
		size++;
	}
}
