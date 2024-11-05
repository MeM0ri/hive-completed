/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:04:53 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/05 10:41:47 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_substr(char const *s, char c)
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

static size_t	ft_count_chars(char const *s, char c)
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

static int		ft_split_string(char const *s, char c, char** splitted_string)
{
	unsigned int	start;
	unsigned int	count;
	size_t			char_count;

	start = 0;
	count = 0;
	while (s[start])
	{
		char_count = ft_count_chars(&s[start], c);
		splitted_string[count] = (char *)malloc(sizeof(char) * (char_count + 1));
		splitted_string[count] = ft_substr(s, start, char_count);
		if (!splitted_string)
			return (1);
		start += char_count;
		count++;
	}
	splitted_string[count] = NULL;
	return (0);
}

char			**ft_split(char	const *s, char c)
{
	char	**splitted_string;
	size_t	substr_count;
	int		split_check;

	substr_count = ft_count_substr(s, c);
	splitted_string = (char **)malloc(sizeof(char *) * (substr_count + 1));
	if (!splitted_string)
		return (NULL);
	split_check = ft_split_string(s, c, splitted_string);
	if (split_check == 0)
		return (splitted_string);
	return (NULL);
}
