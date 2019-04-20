/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:33:47 by smorty            #+#    #+#             */
/*   Updated: 2019/04/20 18:30:37 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static int is_empty_row(char *line)
{
	while (*line)
	{
		if (*line != '.')
			return (0);
		line++;
	}
	return (1);
}

static void remove_empty_cols(t_tetris **list)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < (*list)->rows)
	{
		if ((*list)->figure[i][0] == '.')
			count++;
		i++;
	}
	if (count == (*list)->rows)
	{
		while (i)
		{
			i--;
			(*list)->figure[i] = ft_strcpy((*list)->figure[i], &(*list)->figure[i][1]);
		}
		(*list)->cols--;
	}
	if (count == (*list)->rows)
		remove_empty_cols(&*list);
	else
		return ;
}

static void	new_piece(int fd, t_tetris **list)
{
	char *line;
	static int num = 0;
	int i;
	int j;
	int k;
	int n;

	*list = (t_tetris *)malloc(sizeof(t_tetris));
	(*list)->next = NULL;
	(*list)->figure = (char **)malloc(sizeof(char *) * 5);
	k = 0;
	i = 0;
	while ((n = get_next_line(fd, &line)) && i < 4)
	{
		if (!is_empty_row(line))
		{
			(*list)->figure[k] = (char *)malloc(sizeof(char) * 5);
			ft_bzero((*list)->figure[k], 5);
			j = 0;
			while (*(line + j))
			{
				if (*(line + j) == '.')
					(*list)->figure[k][j] = '.';
				else
					(*list)->figure[k][j] = *(line + j) + 30 + num;
				j++;
			}
			(*list)->figure[k][j] = '\0';
			k++;
		}
		i++;
	}
	(*list)->figure[k] = NULL;
	(*list)->cols = j;
	(*list)->rows = k;
	remove_empty_cols(list);
	num++;
	if (n)
		new_piece(fd, &(*list)->next);
	else
		return ;
}

t_tetris	*store_pieces(int fd)
{
	t_tetris *figures;

	figures = (t_tetris *)malloc(sizeof(t_tetris));
	figures->next = NULL;
	new_piece(fd, &figures);
	return (figures);
}
