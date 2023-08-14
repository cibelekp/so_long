/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:01:30 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 16:03:06 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	char	l;

	l = '\n';
	if (fd < 0)
		return ;
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, &l, 1);
}

/*
writes a string and adds a new line in a file pointed by fd number
similar to ft_putstr_fd but adds a new line at the end
*/