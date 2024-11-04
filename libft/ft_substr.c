/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:26:15 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/04 12:40:51 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			size;
	unsigned int	i;

	if (len > 0 && ft_strlen(s) > start)
	{
		if (ft_strlen(s) - start > len)
			size = len;
		else
			size = ft_strlen(s) - start;
		substr = (char *)malloc(sizeof(char) * size + 1);
		i = 0;
		while (size-- > 0)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
