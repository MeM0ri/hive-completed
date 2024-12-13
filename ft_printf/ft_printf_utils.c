/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/13 16:15:27 by alfokin          ###   ########.fr       */
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

int	ft_putpointer(unsigned long long p)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (ft_puthex(p, 2, 'x'));
}

int	ft_putui(unsigned int n)
{
	if (n >= 10)
		return (ft_putui(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
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

int	ft_puthex(unsigned long long n, int count, const char type)
{
	if (n >= 16)
	{
		count++;
		ft_puthex(n / 16, count, type);		//bug is somwhere there!
		count++;
		ft_puthex(n % 16, count, type);
	}
	else
	{
		if (n < 10)
			ft_putchar(n % 16 + '0');
		else if (type == 'X')
			ft_putchar(n + 'A' - 10);
		else
			ft_putchar(n + 'a' - 10);
	}
	return (count);
}
