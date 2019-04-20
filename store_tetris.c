/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:33:47 by smorty            #+#    #+#             */
/*   Updated: 2019/04/20 19:37:47 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_empty(char *line)
{
	while (*line)
	{
		if (*line != '.')
			return (0);
		line++;
	}
	return (1);
}

static void	shift_to_left(t_tetris **list)
{
	int count;
	int i;

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
		shift_to_left(&*list);
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
	while ((rd = get_next_line(fd, &line)) && *line != '\0')
	{
		if (!is_empty(line))
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
	shift_to_left(&list);
	num++;
	if (rd)
		list->next = store_tetris(fd);
	return (list);
}
