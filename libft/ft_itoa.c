/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:26:29 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 21:07:15 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_int(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		len = len + 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char		*str;
	size_t		len;
	long int	n;

	n = nb;
	len = ft_size_int(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

/*
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled
The function itoa() always returns the value string. There is no error return.
*/