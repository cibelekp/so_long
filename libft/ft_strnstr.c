/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:40:10 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/08 20:21:45 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		x = 0;
		while (little[x] == big[i + x] && (i + x) < len)
		{
			if (little[x + 1] == '\0')
				return ((char *)&big[i]);
			x++;
		}
		i++;
	}
	return (0);
}

/*
 The strnstr() function locates the first occurrence of the null-termi-
     nated string little in the string big, where not more than len characters
     are searched. Characters that appear after a `\0' character are not
     searched.
*/