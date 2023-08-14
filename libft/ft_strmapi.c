/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:12:03 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 21:13:02 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s2;
	unsigned int	i;

	s2 = (char *)malloc(ft_strlen(s) + 1);
	i = -1;
	if (!s2)
		return (NULL);
	while (s[++i])
		s2[i] = f(i, s[i]);
	s2[i] = '\0';
	return (s2);
}

	//strlen s
	// malloc s2
	//while s, s2 = f(s[i]); i++;
	// null terminate s2

//f(i, &s[i]) -> how to run the function correctly
