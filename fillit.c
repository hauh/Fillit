/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/22 18:04:47 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_square(char **square, int i)
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

static int	starting_size(int count)
{
	int n;

	n = 2;
	while (n * n < count * 4)
		n++;
	return (n);
}

char		**fillit(t_tetris **list, int count)
{
	char	**square;
	int		size;

	size = starting_size(count);
	square = create_square(size);
	while (solve(square, list, size, 0, 0))
	{
		free_square(square, size);
		size++;
		square = create_square(size);
		if (!square)
			return (NULL);
	}
	return (square);
}
