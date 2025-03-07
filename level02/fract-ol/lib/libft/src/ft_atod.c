/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:45:53 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/07 12:53:35 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

double	count_fraction(const char *nptr)
{
	double	fraction;
	double	divider;

	fraction = 0.0;
	divider = 10.0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		fraction += (*nptr - '0') / divider;
		divider *= 10.0;
		nptr++;
	}
	return (fraction);
}

double	ft_atod(const char *nptr)
{
	int		sign;
	double	result;

	result = 0.0;
	sign = 1;
	while (*nptr == ' ' || (*nptr > 8 && *nptr < 14))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10.0 + (*nptr - '0');
		nptr++;
	}
	if (*nptr == '.')
	{
		nptr++;
		result += count_fraction(nptr);
	}
	return (result * sign);
}
