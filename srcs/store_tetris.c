/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:33:47 by smorty            #+#    #+#             */
/*   Updated: 2019/04/23 19:31:05 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		is_empty_row(char *line)
{
	char *clear;

	clear = line;
	while (*line)
	{
		if (*line != '.')
			return (0);
		line++;
	}
	free(clear);
	return (1);
}

static void		trim_empty_cols(t_tetris *list)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	while (j < list->cols)
	{
		i = 0;
		while ((i < list->rows) && (list->figure[i][j] == '.'))
			i++;
		if (i == list->rows)
		{
			i = 0;
			while (i < list->rows)
			{
				s = &list->figure[i][j];
				while (*s++)
					*(s - 1) = *s;
				i++;
			}
			list->cols--;
		}
		else
			j++;
	}
}

static t_tetris	*new_figure(void)
{
	t_tetris *list;

	list = (t_tetris *)malloc(sizeof(t_tetris));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->figure = (char **)malloc(sizeof(char *) * 5);
	if (!list->figure)
	{
		free(list);
		return (NULL);
	}
	list->rows = 0;
	list->cols = 0;
	return (list);
}

static char		*write_line(t_tetris *list, char *line, int num)
{
	if (!(list->figure[list->rows] = (char *)malloc(sizeof(char) * 5)))
	{
		free_square(list->figure, list->rows);
		free(list);
		return (NULL);
	}
	ft_bzero(list->figure[list->rows], 5);
	list->cols = 0;
	while (line[list->cols])
	{
		if (line[list->cols] == '.')
			list->figure[list->rows][list->cols] = '.';
		else
			list->figure[list->rows][list->cols] = line[list->cols] + num;
		list->cols++;
	}
	free(line);
	list->rows++;
	return (list->figure[list->rows - 1]);
}

t_tetris		*store_tetris(int fd)
{
	static int	num = 30;
	t_tetris	*list;
	char		*line;
	int			rd;

	if (!(list = new_figure()))
		return (NULL);
	while ((rd = get_next_line(fd, &line)) && line && *line)
		if (!is_empty_row(line))
			if (!(list->figure[list->rows] = write_line(list, line, num)))
				return (NULL);
	list->figure[list->rows] = NULL;
	trim_empty_cols(list);
	num++;
	if (rd)
	{
		free(line);
		if (!(list->next = store_tetris(fd)) || rd < 0)
		{
			free_square(list->figure, list->rows);
			free(list);
			return (NULL);
		}
	}
	return (list);
}
