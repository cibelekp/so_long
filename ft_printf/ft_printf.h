/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:44:07 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/17 19:00:58 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define BASEX "0123456789abcdef"
# define BASEXUP "0123456789ABCDEF"

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnb(int nb);
int	put_u(unsigned int nb);
int	put_hexa(unsigned int nb, char *base);
int	put_p(unsigned long int ptr, char *base, int address0x);

#endif