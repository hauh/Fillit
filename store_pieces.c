/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:33:47 by smorty            #+#    #+#             */
/*   Updated: 2019/04/19 20:02:09 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int is_empty(char *line)
{
	while (*line)
	{
		if (*line != '.')
			return (0);
		line++;
	}
	return (1);
}

static void	new_piece(int fd, t_piece **figures)
{
	char *line;
	static int num = 0;
	int i;
	int j;
	int k;
	int n;

	*figures = (t_piece *)malloc(sizeof(t_piece));
	(*figures)->next = NULL;
	k = 0;
	i = 0;
	while ((n = get_next_line(fd, &line)) && i < 4)
	{
		if (!is_empty(line))
		{
			j = 0;
			while (*(line + j))
			{
				if (*(line + j) == '.')
					(*figures)->fig[k][j] = '0';
				else
					(*figures)->fig[k][j] = *(line + j) + 30 + num;
				j++;
			}
			(*figures)->fig[k][j] = '\0';
			printf("%s\n", (*figures)->fig[k]);
			k++;
		}
		i++;
	}
	(*figures)->cols = j;
	(*figures)->rows = k;
	printf("cols = %d\n", (*figures)->cols);
	printf("rows = %d\n", (*figures)->rows);
	num++;
	if (n)
		new_piece(fd, &(*figures)->next);
	else
		return ;
}

t_piece	*store_pieces(int fd)
{
	t_piece *figures;

	figures = (t_piece *)malloc(sizeof(t_piece));
	figures->next = NULL;
	new_piece(fd, &figures);
	return (figures);
}
