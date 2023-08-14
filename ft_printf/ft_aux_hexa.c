/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:54:46 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/17 18:55:15 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hexa(unsigned int nb, char *base)
{
	int	len;

	len = 0;
	if (nb >= 16)
		len += put_hexa(nb / 16, base);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

int	put_p(unsigned long int ptr, char *base, int address0x)
{
	int	len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	if (address0x == 1)
		len += write(1, "0x", 2);
	if (ptr >= 16)
		len += put_p(ptr / 16, base, 0);
	len += ft_putchar(base[ptr % 16]);
	return (len);
}
