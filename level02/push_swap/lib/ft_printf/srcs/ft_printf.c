/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/19 16:34:12 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_check_format(const char format)
{
	char	*available_formats;

	available_formats = "cspdiuxX%";
	while (*available_formats)
	{
		if (format == *available_formats)
			return (1);
		available_formats++;
	}
	return (-1);
}

int	ft_args_parse(const char format, va_list args)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (format == 'u')
		return (ft_putui(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 0, format));
	else if (format == '%')
		return (ft_putchar('%'));
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
			if (*format == '\0' || ft_check_format(*format) != 1)
			{
				count = -1;
				break ;
			}
			count += ft_args_parse(*format, args);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
