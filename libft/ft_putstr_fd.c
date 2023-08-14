/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:59:14 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 16:00:47 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (!s || !fd)
		return ;
	write(fd, s, ft_strlen(s));
}

/*
writes a string in a file pointed by fd number
*/