/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:55:20 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/06 16:33:59 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_temp;

	i = 0;
	s_temp = (unsigned char *)s;
	while (i < n)
	{
		s_temp[i] = c;
		i++;
	}
	return (s);
}
