/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 15:58:37 by smorty            #+#    #+#             */
/*   Updated: 2019/04/19 20:02:20 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	int fd;
	t_piece *new;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		new = store_pieces(fd);
		fillit(&new);
	}
	return (0);
}
