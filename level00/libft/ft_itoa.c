/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:05:32 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/05 12:41:19 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_length(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static void	ft_convert(char *c_num, long n, int i)
{
	while (i-- > 0)
	{
		c_num[i] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*c_num;
	int		sign;
	int		length;
	long	num_to_convert;

	sign = 0;
	num_to_convert = (long)n;
	if (n < 0)
	{
		sign = 1;
		num_to_convert = -num_to_convert;
	}
	length = ft_int_length(n) + sign;
	c_num = (char *)malloc(sizeof(char) * (length + 1));
	if (!c_num)
		return (NULL);
	c_num[length] = '\0';
	ft_convert(c_num, num_to_convert, length);
	if (sign)
		c_num[0] = '-';
	return (c_num);
}
