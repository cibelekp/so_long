/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:22:15 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/09 13:29:16 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s) + 1;
	s2 = malloc(len * sizeof (char));
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s, len);
	return (s2);
}
