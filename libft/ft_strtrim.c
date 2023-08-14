/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:28:04 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 14:53:10 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*strtrim;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != 0)
		start++;
	while (end >= start && ft_strchr(set, s1[end]) != 0)
		end--;
	len = end - start + 1;
	strtrim = ft_substr(s1, start, len);
	if (!strtrim)
		return (NULL);
	return (strtrim);
}

/*
serve para cortar um "set" de caracteres aleatorio do inicio e fim de uma string
ex: tirar os whitespaces de "    Hello World   " (set = " ")
ex: s1 = "aaabxaropecdba" / set = "abcd" / s1_trimmed = "xarope"

Allocates (with malloc(3)) and returns a copy of ’s1’ 
com o set como marcador

*/