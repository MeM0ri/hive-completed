/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 09:53:51 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/26 10:08:01 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *arc)
{
	char	*result;
	int	i;

	result = (char *)malloc(ft_str_length(arc));
	i = 0;
	while (arc[i])
	{
		result[i] = arc[i];
		i++;
	}
	return (result);
}
