/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:39:52 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/17 18:39:52 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sort_args(char type, va_list arg)
{
	if (type == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnb(va_arg(arg, int)));
	else if (type == 'u')
		return (put_u(va_arg(arg, unsigned int)));
	else if (type == 'x')
		return (put_hexa(va_arg(arg, unsigned int), BASEX));
	else if (type == 'X')
		return (put_hexa(va_arg(arg, unsigned int), BASEXUP));
	else if (type == 'p')
		return (put_p(va_arg(arg, unsigned long int), BASEX, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '%')
				len += write(1, &str[i], 1);
			else
				len += sort_args(str[i], args);
		}
		else
		{
			write(1, &str[i], 1);
			len++;
		}
	}
	va_end(args);
	return (len);
}

/*
INSTRUCTIONS:
-prototyped similarly to printf
-won’t do the buffer management in the printf function
-manage following conversions: sSpdDioOuUxXcC
-manage %%
-manage flags #0-+space
-manage min field-width
-manage precision
-manage flags hh, h, 1, 11, j, z

REMINDER:
The var_type argument must be one of int, long, decimal, double, struct, union,
	or pointer, or a typedef of one of these types.
*/