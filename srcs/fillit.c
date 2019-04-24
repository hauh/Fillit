/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/24 20:28:24 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_square(char **square, int i)
{
	while (i)
	{
		i--;
		free(square[i]);
	}
	free(square);
}

static char	**create_square(int size)
{
	char	**square;
	int		i;

	square = (char **)malloc(sizeof(char *) * (size + 1));
	if (!square)
		return (NULL);
	i = 0;
	while (i < size)
	{
		square[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!square[i])
		{
			free_square(square, i);
			return (NULL);
		}
		ft_memset(square[i], '.', size);
		square[i][size] = '\0';
		i++;
	}
	square[i] = NULL;
	return (square);
}

static int	starting_size(t_tetris *list)
{
	int figures;
	int n;

	figures = 0;
	while (list)
	{
		figures++;
		list = list->next;
	}
	n = 2;
	while (n * n < figures * 4)
		n++;
	return (n);
}

char		**fillit(t_tetris *list)
{
	char	**square;
	int		size;

	size = starting_size(list);
	square = create_square(size);
	if (!square)
		return (NULL);
	while (solve(square, list, 0, 0))
	{
		free_square(square, size);
		size++;
		square = create_square(size);
		if (!square)
			return (NULL);
	}
	return (square);
}
