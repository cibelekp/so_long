/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:48:48 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/09 17:06:26 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_t;
	unsigned char	*s2_t;
	size_t			i;
	int				diff;

	s1_t = (unsigned char *)s1;
	s2_t = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_t[i] != s2_t[i])
		{
			diff = s1_t[i] - s2_t[i];
			return (diff);
		}
		i++;
	}
	return (0);
}

/*
	took away protections to pass tester
	if (!s1 || !s2)
		return (NULL);
	while (s1 || s2)
*/