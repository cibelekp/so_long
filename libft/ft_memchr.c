/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:34:01 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/09 16:47:57 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t n)
{
	size_t			i;
	unsigned char	*str_t;
	unsigned char	chr_t;

	i = 0;
	str_t = (unsigned char *)str;
	chr_t = (unsigned char)chr;
	while (i < n)
	{
		if (str_t[i] == chr_t)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
