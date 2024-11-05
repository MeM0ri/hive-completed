/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:16 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/05 16:12:02 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check_str(char const *s1, char const *set)
{
	size_t	trimmed_size;
	size_t	i;

	trimmed_size = ft_strlen(s1);
	while (*s1)
	{
		i = 0;
		while (set[i])
		{
			if (*s1 == set[i])
			{
				trimmed_size--;
				break ;
			}
			i++;
		}
		s1++;
	}
	return (trimmed_size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	trimmed_size;
	size_t	i;
	size_t	j;

	trimmed_size = ft_check_str(s1, set);
	trimmed_str = (char *)malloc(sizeof(char) * (trimmed_size + 1));
	if (trimmed_size == 0 || !trimmed_str)
		return (NULL);
	j = 0;
	while (*s1)
	{
		i = 0;
		while (set[i] && *s1 != set[i])
			i++;
		if (set[i] != *s1)
		{
			trimmed_str[j] = *s1;
			j++;
		}
		s1++;
	}
	return (trimmed_str);
}
