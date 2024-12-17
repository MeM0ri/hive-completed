/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:36:20 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 17:17:06 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int n, int count, t_format *pf)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648", pf));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n > 9)
		count = ft_putnbr(n / 10, count, pf);
	ft_putchar(n % 10 + '0');
	count++;
	return (count);
}
