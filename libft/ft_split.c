/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:04:53 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/12 13:14:14 by alfokin          ###   ########.fr       */
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
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

static int	ft_split_string(char const *s, char c, char **splitted_str)
{
	unsigned int	start;
	unsigned int	count;
	size_t			c_count;

	start = 0;
	count = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		if (s[start])
		{
			c_count = ft_count_chars(&s[start], c);
			//splitted_str[count] = (char *)malloc(sizeof(char) * (c_count + 1));
			splitted_str[count] = ft_substr(s, start, c_count);
			if (!splitted_str[count])
				return (1);
			start += c_count;
			count++;
		}
	}
	splitted_str[count] = NULL;
	return (0);
}

char	**ft_split(char	const *s, char c)
{
	char	**splitted_str;
	size_t	substr_count;
	int		split_check;

	if (!s)
		return (NULL);
	substr_count = ft_count_substr(s, c);
	splitted_str = (char **)malloc(sizeof(char *) * (substr_count + 1));
	if (!splitted_str)
		return (NULL);
	split_check = ft_split_string(s, c, splitted_str);
	if (split_check == 0)
		return (splitted_str);
	return (NULL);
}
