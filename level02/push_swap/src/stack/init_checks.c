/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:19 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/11 14:29:32 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	is_valid_value(char *value)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*value == '\0')
		return (false);
	if (*value == '-' || *value == '+')
	{
		if (*value == '-')
			sign = -1;
		value++;
		if (*value == '\0')
			return (false);
	}
	while (*value)
	{
		if (!ft_isdigit(*value))
			return (false);
		num = 10 * num + (*value - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num < INT_MIN))
			return (false);
		value++;
	}
	return (true);
}

bool	is_duplicates(int *numbers, int stack_size)
{
	int	i;
	int	j;

	i = 0;
	while (i - 1 < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (numbers[i] == numbers[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
