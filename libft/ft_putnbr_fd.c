/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:03:59 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/10 17:41:41 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = n * (-1);
	}
	n = (unsigned int)n;
	if (n >= 10)
		ft_putnbr_fd((unsigned int)n / 10, fd);
	ft_putchar_fd((unsigned int)n % 10 + '0', fd);
}

/*
Test fsoares:
Error in test 5: ft_putnbr_fd(-2147483648, fd: -1): expected: 
"0\n10000043\n-10000043\n2147483647\n-2147483648\n", content of the file: ""
*/
