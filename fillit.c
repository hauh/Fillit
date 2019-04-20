/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:25:30 by smorty            #+#    #+#             */
/*   Updated: 2019/04/19 21:10:27 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

// IT DOESNT WORK

static int solve(char ***square, t_piece **pieces, unsigned int size)
{
	int i;

	i = 0;
	while ((*square)[i])
	{
		if ((ft_strlen((*square)[i]) + ft_strlen((*pieces)->fig[0])) <= size)
			(*square)[i] = ft_strcat((*square)[i], (*pieces)->fig[0]);
		else
			return (1);
		i++;
	}
	printf("first line: %s\n", (*square)[0]);
	printf("%s\n", (*pieces)->next->fig[0]);
	if (i < (*pieces)->rows)
	{
		printf("!!!");
		if ((*pieces)->next)
			return (solve(&*square, &(*pieces)->next, size));
		printf("return 0\n");
		return (0);
	}
	return (1);
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
		ft_memset(square[i], '0', size);
		square[i][size] = '\0';
		i++;
	}
	square[size] = NULL;
	printf("square size: %d\n", size);
	return (square);
}

void fillit(t_piece **pieces)
{
	unsigned int size;
	char **square;

	size = 2;
	while (size < 16)
	{
		square = create_square(size);
		if (!solve(&square, pieces, size))
			break ;
		size++;
	}
}
