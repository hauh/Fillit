/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:37 by smorty            #+#    #+#             */
/*   Updated: 2019/04/22 16:38:52 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void print_solution(char **square)
{
	int i;

	i = 0;
	while (square[i])
	{
		ft_putendl(square[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int fd;
	int count;
	char **solution;
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
		solution = fillit(&new, count);
		print_solution(solution);
	}
	return (0);
}
