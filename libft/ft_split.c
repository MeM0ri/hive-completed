/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:04:53 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/12 16:44:30 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **splitted_string, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (splitted_string[i] != NULL)
			free(splitted_string);
		i++;
	}
	free(splitted_string);
}

static size_t	ft_count_substr(char const *s, char c)
{
	size_t	substr_count;
	size_t	i;

	substr_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			substr_count++;
		while (s[i] && s[i] != c)
			i++;
	}
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
	ft_free_split(splitted_str, substr_count);
	return (NULL);
}
