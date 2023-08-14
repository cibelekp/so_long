/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:47:00 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 17:51:01 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefix, char const *suffix)
{
	size_t	len_prefix;
	size_t	len_suffix;
	char	*buffer;

	len_prefix = ft_strlen(prefix);
	len_suffix = ft_strlen(suffix);
	buffer = (char *)malloc(len_prefix + len_suffix + 1);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, (const void *)prefix, len_prefix);
	ft_memcpy(&buffer[len_prefix], (const void *)suffix, len_suffix);
	buffer[len_prefix + len_suffix] = '\0';
	return ((char *)buffer);
}

/* 
Allocates (with malloc(3)) and returns a new string,
which is the result of the concatenation of ’prefix’ and ’suffix’.
*/