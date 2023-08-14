/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:07:10 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/09 17:15:14 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elements, size_t bytes)
{
	void	*ptr;

	ptr = malloc(elements * bytes);
	if (!ptr)
		return (NULL);
	else
		ft_bzero(ptr, (elements * bytes));
	return (ptr);
}

/* 
allocates memory for an array of n elements of x bytes each
returns a pointer to the allocated memory

*/