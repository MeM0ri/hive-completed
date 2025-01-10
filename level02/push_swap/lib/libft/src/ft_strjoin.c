/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:12:17 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/10 13:42:25 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined_str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * size + 1);
	if (!joined_str)
		return (NULL);
	i = 0;
	while (*s1)
	{
		joined_str[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		joined_str[i] = *s2++;
		i++;
	}
	joined_str[i] = '\0';
	return (joined_str);
}
