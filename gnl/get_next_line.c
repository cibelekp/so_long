/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:26:08 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/14 12:09:07 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*stored;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		ft_bzero_gnl(stash);
		return (NULL);
	}
	stored = NULL;
	while (stash[0] || read(fd, stash, BUFFER_SIZE) > 0)
	{
		stored = joinline(stored, stash);
		if (newline(stash) == 1)
			break ;
	}
	return (stored);
}
