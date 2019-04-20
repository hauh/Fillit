/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:37 by smorty            #+#    #+#             */
/*   Updated: 2019/04/20 19:30:18 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

static void print_figures(t_tetris **list)
{
	int i;

	i = 0;
	if (*list)
	{
		while ((*list)->figure[i])
		{
			printf("%s\n", (*list)->figure[i]);
			i++;
		}
		printf("rows: %d\n", (*list)->rows);
		printf("cols: %d\n", (*list)->cols);
		printf("\n");
		print_figures(&(*list)->next);
	}
}

int		main(int argc, char **argv)
{
	int fd;
	t_tetris *new;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		new = store_tetris(fd);
		print_figures(&new);
//		fillit(&new);
	}
	return (0);
}
