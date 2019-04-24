/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:04:00 by smorty            #+#    #+#             */
/*   Updated: 2019/04/24 16:47:58 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_wrong_line(char *line)
{
	int dash;
	int dot;

	dash = 0;
	dot = 0;
	if ((line[4] != '\n') && (line[9] != '\n') && (line[14] != '\n')
		&& (line[19] != '\n'))
		return (1);
	while (*line)
	{
		if (*line == '#')
			dash++;
		if (*line == '.')
			dot++;
		line++;
	}
	if ((dash == 4) && (dot == 12))
		return (0);
	return (1);
}

static int	check_figure(char *line, char *line0, char *line20)
{
	int res;

	if (*line == '#')
	{
		res = 1;
		*line = '*';
		if (line + 5 <= line20)
			res += check_figure(line + 5, line0, line20);
		if (line + 1 <= line20)
			res += check_figure(line + 1, line0, line20);
		if (line - 1 >= line0)
			res += check_figure(line - 1, line0, line20);
	}
	else
		return (0);
	return (res);
}

static int	check(char *buf)
{
	char *dash;

	if (is_wrong_line(buf))
		return (1);
	dash = buf;
	while (*dash != '#')
		dash++;
	if (check_figure(dash, buf, &buf[20]) != 4)
		return (1);
	return (0);
}

static int	is_wrong_figures(int fd)
{
	char	buf[22];
	int		rd;

	ft_bzero(buf, 22);
	rd = read(fd, buf, 21);
	if (rd <= 0)
		return (1);
	while (rd && rd == 21)
	{
		if (check(buf))
			return (1);
		ft_bzero(buf, 22);
		rd = read(fd, buf, 21);
		if (rd < 0)
			return (1);
	}
	if (check(buf))
		return (1);
	return (0);
}

void		validate(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	if (is_wrong_figures(fd))
	{
		close(fd);
		error();
	}
}
