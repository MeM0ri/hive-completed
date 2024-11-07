/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 00:26:15 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/07 12:15:21 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			size;
	unsigned int	i;

	if (start > ft_strlen(s))
		size = 0;
	else if (ft_strlen(s) - start > len)
		size = len;
	else
		size = ft_strlen(s) - start;
	if (!(substr = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (size-- > 0)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
