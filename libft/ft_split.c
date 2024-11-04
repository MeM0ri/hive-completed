/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:04:53 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/04 16:42:20 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_substr(char const *s, char c)
{
	size_t	substr_count;

	substr_count = 0;
	while (*s)
	{
		if (*s == c)
			substr_count++;
		s++;
	}
	substr_count++;
	return (substr_count);
}

size_t	ft_count_chars(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	if (*s == c)
		count++;
	return (count);
}

char	**ft_split(char	const *s, char c)
{
	char			**splited_string;
	size_t			substr_count;
	size_t			char_count;
	unsigned int	start;
	unsigned int	count;

	substr_count = ft_count_substr(s, c);
	splited_string = (char **)malloc(sizeof(char *) * (substr_count + 1));
	if (!splited_string)
		return (NULL);
	start = 0;
	count = 0;
	while (s[start])
	{
		char_count = ft_count_chars(&s[start], c);
		splited_string[count] = (char *)malloc(sizeof(char) * (char_count + 1));
		if (!splited_string)
			return (NULL);
		splited_string[count] = ft_substr(s, start, char_count);
		start += char_count;
		count++;
	}
	splited_string[count] = NULL;
	return (splited_string);
}
