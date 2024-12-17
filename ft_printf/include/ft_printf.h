/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 17:18:29 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>
//#include <unistd.h>

typedef	struct	s_format
{
	int		left_align;
	int		zero_padding;
	int		field_width;
	int		precision;
	char	specifier;
}	t_format;


int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s, t_format *pf);
int	ft_putptr(void *ptr);
int	ft_putui(unsigned int n);
int	ft_putnbr(int n, int count, t_format *pf);
int	ft_puthex(unsigned long long n, int count, const char type);
void ft_parse_format(const char **format, t_format *pf);

#endif
