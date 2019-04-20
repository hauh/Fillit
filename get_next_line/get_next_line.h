/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:53:26 by smorty            #+#    #+#             */
/*   Updated: 2019/04/18 19:37:57 by smorty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

typedef struct	s_file
{
	char			*tail;
	int				file;
	struct s_file	*next;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif
