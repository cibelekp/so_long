/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:57:05 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/09 19:45:25 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_src = ft_strlen(src);
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (size > (i + j + 1) && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (len_src + i);
}
