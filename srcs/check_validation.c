/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:28:25 by ckatelin          #+#    #+#             */
/*   Updated: 2019/04/19 16:22:31 by ckatelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	ft_check_dline(char **str)
{
	int i;

	i = 0;
	while ((*str[i] != '\n' || *str[i] != '\0') && i < 5)
		i++;
	if (i == 5)
		return (1);
	return (0);
}

static	int ft_check_val(int **mas)
{
	int k;
	int i;
	int count;

	while (mas[k])
	{
		i = -1;
		count = 0;
		while (mas[k][++i])
		{
			if (k < 4 && i < 4)
			{
				if ((mas[k + 1][i + 1] + mas[k][i]) == 1 &&
						(mas[k][i] + mas[k + 1][i + 1] + mas[k + 1][i] + mas[k][i + 1] == 4))
					return (0);
			}
			if (mas[k][i] == 1)
				count++;
			if (count > 4)
				return (0);
		}
		k++;
	}
}

static	int	ft_check_pos(int fd, char **line, int figures)
{
	int k;
	static int *checking;
	int i;

	k = 0;
	i = 0;
	if (!(checking = (int **)malloc(sizeof(int *) * (figures))))
		return (0);
	while (get_next_line(fd, line) == 1)
	{
		if (!(checking[k] = (int *)malloc(sizeof(int) * 5)))
			return (0);
		if (*line != "\n")
		{
			while (*line[i] != '\n' || *line[i] != '\0')
			{
				if (*line[i] == '.')
					checking[k][i++] = 0;
				else if (*line[i] == '#')
					checking[k][i++] = 1;
				else
					return (0);
			}
		}
		else
		{
			k++;
			i = 0;
		}
	}
	checking[k] = 0;
	if (ft_check_val(checking) == 0)
	{
		ft_strdel(&strdel); //NEED FREE ALL
		return (0);
	}
	ft_strdel(&checking); //NEED FREE ALL
	return (1);
}

int		check_validation(int fd) //BETTER PUT TO ARGUMENTS 
{
	int count;
	int red;
	int *line;
	int i;

	red = 0;
	count = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (*line != "\n" && count < 4 && ft_check_dlina(&line))
		{
			count++;
			i++;
		}
		if (count == 4 && *line == "\n") //I AM NOT SURE ABOIT "\n"
			count = 0;
		else
			red = 1;
		if (red)
			break ;
	}
	if (red && ft_check_pos(fd, &line), (i / 4)) //NEED NEW FD BECAUSE MAY BE READ IS ALREADY 0
	{
		print_error;
		return (0);
	}
	return (1);
}
