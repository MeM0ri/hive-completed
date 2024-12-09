/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/09 16:56:00 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_args_parse(const char arg_type, va_list args)
{
	if (arg_type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (arg_type == 's')
		return (ft_putstr(va_arg(args, char *)));
//	else if (arg_type == 'p')
	else if (arg_type == 'd')
		return (ft_putnbr(va_arg(args, int), 0)); //Fix to print out decimals
	else if (arg_type == 'i')
		return (ft_putnbr(va_arg(args, int), 0)); //Fix out of range int
//	else if (arg_type == 'u')
	else if (arg_type == 'x')
		return (ft_puthex(va_arg(args, int), 0, 'x'));
	else if (arg_type == 'X')
		return (ft_puthex(va_arg(args, int), 0, 'X'));
	else if (arg_type == '%')
		return (ft_putchar(va_arg(args, int)));
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
			count += ft_args_parse(*format, args);
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
