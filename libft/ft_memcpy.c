/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:44:50 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/09 16:32:15 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_t;
	unsigned char	*src_t;

	i = 0;
	dest_t = (unsigned char *)dest;
	src_t = (unsigned char *)src;
	if (!dest_t && !src_t)
		return (NULL);
	while (i < n)
	{
		dest_t[i] = src_t[i];
		i++;
	}
	return (dest);
}
