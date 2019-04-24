/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 20:04:00 by smorty            #+#    #+#             */
/*   Updated: 2019/04/24 19:46:19 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_wrong_chars(char *line)
{
	int dash;
	int dot;

	if ((line[4] != '\n') || (line[9] != '\n') ||
		(line[14] != '\n') || (line[19] != '\n'))
		return (1);
	dash = 0;
	dot = 0;
	while (*line)
	{
		if (*line == '#')
			dash++;
		if (*line == '.')
			dot++;
		line++;
	}
	if ((dash != 4) || (dot != 12))
		return (1);
	return (0);
}

static int	check_figure(char *line, char *line0, char *line20)
{
	int count;

	if (*line == '#')
	{
		count = 1;
		*line = '.';
		if (line + 5 <= line20)
			count += check_figure(line + 5, line0, line20);
		if (line + 1 <= line20)
			count += check_figure(line + 1, line0, line20);
		if (line - 1 >= line0)
			count += check_figure(line - 1, line0, line20);
	}
	else
		return (0);
	return (count);
}

static int	is_wrong_figure(char *buf)
{
	char *dash;

	if (is_wrong_chars(buf))
		return (1);
	dash = buf;
	while (*dash != '#')
		dash++;
	if (check_figure(dash, buf, &buf[20]) != 4)
		return (1);
	return (0);
}

static int	is_wrong_file(int fd)
{
	char	buf[22];
	int		rd;
	int		count;

	ft_bzero(buf, 22);
	rd = read(fd, buf, 21);
	if (rd <= 0)
		return (1);
	count = 0;
	while (rd == 21)
	{
		count++;
		if (count > 25 || is_wrong_figure(buf))
			return (1);
		ft_bzero(buf, 22);
		rd = read(fd, buf, 21);
		if (rd < 0)
			return (1);
	}
	if (is_wrong_figure(buf))
		return (1);
	return (0);
}

void		validate(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	if (is_wrong_file(fd))
	{
		close(fd);
		error();
	}
	close(fd);
}
