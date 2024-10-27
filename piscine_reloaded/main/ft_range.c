/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:00:03 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/26 15:34:08 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	result = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		result[i] = min++;
		i++;
	}
	return (result);
}
