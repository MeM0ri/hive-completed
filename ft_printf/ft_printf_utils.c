/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/09 16:57:35 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		ft_putchar(s[count++]);
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, count);
		count++;
	}
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}

int	ft_putnbr_hex_base(int n, int count)
{
	char	base_chars[16];

	base_chars[0] = '0';
	base_chars[1] = '1';
	base_chars[2] = '2';
	base_chars[3] = '3';
	base_chars[4] = '4';
	base_chars[5] = '5';
	base_chars[6] = '6';
	base_chars[7] = '7';
	base_chars[8] = '8';
	base_chars[9] = '9';
	base_chars[10] = 'A';
	base_chars[11] = 'B';
	base_chars[12] = 'C';
	base_chars[13] = 'D';
	base_chars[14] = 'E';
	base_chars[15] = 'F';
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 16)
	{
		ft_putnbr_hex_base(n / 16, count);
		count++;
	}
	ft_putchar(base_chars[n % 16]);
	count++;
	return (count);
}
