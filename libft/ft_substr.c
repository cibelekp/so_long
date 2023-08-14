/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:34:48 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 14:52:58 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (s && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

/*
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.

parameters:
	s: The string from which to create the substring.
	start: The start index of the substring in the string ’s’.
	len: The maximum length of the substring.
*/