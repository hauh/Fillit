/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/20 23:16:27 by smorty           ###   ########.fr       */
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
			square[y + i][x + j] = (*list)->figure[i][j];
			j++;
		}
		i++;
	}
}

static int solve(char **square, t_tetris **list, int size)
{
	int i;
	int j;

	if (*list)
	{
		i = 0;
		while (i + (*list)->rows <= size)
		{
			j = 0;
			while (j + (*list)->cols <= size)
			{
				printf("spot[%d][%d]: %d\n", i, j, check_spot(square, list, i, j));
				if (!check_spot(square, list, i, j))
				{
					add_piece(square, list, i, j);
					i = size;
					print_solution(&*square);
					printf("add next\n");
					return (solve(square, &(*list)->next, size));
					break;
				}
				j++;
			}
			i++;
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
		if (!solve(square, list, size))
			break ;
		size++;
	}
}
