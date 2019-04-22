/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:37 by smorty            #+#    #+#             */
/*   Updated: 2019/04/22 14:47:28 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/*
static void print_figures(t_tetris **list)
{
	int i;

	i = 0;
	if (*list)
	{
		while ((*list)->figure[i])
		{
			ft_putendl((*list)->figure[i]);
			i++;
		}
		ft_putchar('\n');
		print_figures(&(*list)->next);
	}
}
*/
int		main(int argc, char **argv)
{
	int fd;
	int count;
	t_tetris *new;
	t_tetris *tmp;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		new = store_tetris(fd);
		count = 0;
		tmp = new;
		while (tmp)
		{
			count++;
			tmp = tmp->next;
		}
//		print_figures(&new);
		fillit(&new, count);
	}
	return (0);
}
