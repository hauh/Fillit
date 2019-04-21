/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:33:47 by smorty            #+#    #+#             */
/*   Updated: 2019/04/21 21:34:20 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_empty_row(char *line)
{
	while (*line)
	{
		if (*line != '.')
			return (0);
		line++;
	}
	return (1);
}

static int is_empty_col(char **arr, int col, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		if (arr[i][col] != '.')
			return (0);
		i++;
	}
	return (1);
}

static void shift_string(char *s)
{
	while (*s)
	{
		*s = *(s + 1);
		s++;
	}
}

static void trim_empty_cols(t_tetris **list)
{
	int i;
	int j;

	i = 0;
	while (i < (*list)->cols)
	{
		if (is_empty_col((*list)->figure, i, (*list)->rows))
		{
			j = 0;
			while (j < (*list)->rows)
			{
				shift_string(&(*list)->figure[j][i]);
				j++;
			}
			(*list)->cols--;
		}
		else
			i++;
	}
}

t_tetris	*store_tetris(int fd)
{
	static int	num = 30;
	t_tetris	*list;
	char		*line;
	int			rd;

	list = (t_tetris *)malloc(sizeof(t_tetris));
	list->next = NULL;
	list->figure = (char **)malloc(sizeof(char *) * 5);
	list->rows = 0;
	while ((rd = get_next_line(fd, &line)) && (*line != '\0'))
	{
		if (!is_empty_row(line))
		{
			list->figure[list->rows] = (char *)malloc(sizeof(char) * 5);
			ft_bzero(list->figure[list->rows], 5);
			list->cols = 0;
			while (*(line + list->cols))
			{
				if (*(line + list->cols) == '.')
					list->figure[list->rows][list->cols] = '.';
				else
					list->figure[list->rows][list->cols] = *(line + list->cols) + num;
				list->cols++;
			}
			list->figure[list->rows][list->cols] = '\0';
			list->rows++;
		}
	}
	list->figure[list->rows] = NULL;
	trim_empty_cols(&list);
	num++;
	if (rd)
		list->next = store_tetris(fd);
	return (list);
}
