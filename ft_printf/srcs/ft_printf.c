/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 17:17:39 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_args_parse(const char **format, va_list args)
{
	t_format pf;

	ft_parse_format(format, &pf);
	if (pf.specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (pf.specifier == 's')
		return (ft_putstr(va_arg(args, char *), &pf));
	else if (pf.specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (pf.specifier == 'd')
		return (ft_putnbr(va_arg(args, int), 0, &pf));
	else if (pf.specifier == 'i')
		return (ft_putnbr(va_arg(args, int), 0, &pf));
	else if (pf.specifier == 'u')
		return (ft_putui(va_arg(args, unsigned int)));
	else if (pf.specifier == 'x' || pf.specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 0, pf.specifier));
	else if (pf.specifier == '%')
		return (ft_putchar('%'));
//	else
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_args_parse(&format, args);
			format++;
		}
		else
		{
			ft_putchar(*format);
			format++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
