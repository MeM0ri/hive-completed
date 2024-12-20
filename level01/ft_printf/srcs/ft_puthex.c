/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:36:25 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 14:48:21 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned long long n, int count, const char type)
{
	char			*hex_digits;
	char			buffer[17];
	int				i;

	if (type == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	i = 16;
	buffer[i] = '\0';
	if (n == 0)
		buffer[--i] = '0';
	while (n != 0)
	{
		buffer[--i] = hex_digits[n % 16];
		n /= 16;
	}
	while (buffer[i])
		count += ft_putchar(buffer[i++]);
	return (count);
}
