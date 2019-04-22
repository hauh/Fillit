/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/22 16:36:46 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**create_square(int size)
{
	char	**square;
	int		i;

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
	return (square);
}

static void	free_square(char **square)
{
	int i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		i++;
	}
	free(square);
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
		free_square(square);
		size++;
		square = create_square(size);
	}
	return (square);
}
