/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:50 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/02 17:30:57 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strcpy(char *str, char *new_str, int i)
{
	if (!str || !new_str)
		return (NULL);
	while (*str)
	{
		new_str[i++] = *str;
		str++;
	}
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

int ft_strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *line, char *buffer)
{
	char *new_line;
	int new_line_len;

	new_line_len = ft_strlen(line) + ft_strlen(buffer);
	new_line = (char *)malloc(sizeof(char) * (new_line_len + 1));
	if (!new_line)
		return (NULL);
	ft_strcpy(line, new_line, 0);
	ft_strcpy(buffer, new_line, ft_strlen(line));
	new_line[new_line_len] = '\0';
	if (line)
		free(line);
	return (new_line);
}

// char	*ft_strdup(char *str)
// {
// 	int		len;
// 	char	*str_dup;

// 	len = ft_strlen(str);
// 	str_dup = (char *)malloc(sizeof(char) * (len + 1));
// 	if (!str_dup)
// 		return (NULL);
// 	else
// 		ft_strcpy(str, str_dup, 0);
// 	str_dup[len] = '\0';
// 	return (str_dup);
// }

// size_t	ft_strlen(const char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	if (c == '\0')
// 		return ((char *)&s[ft_strlen(s)]);
// 	while (s[i])
// 	{
// 		if (s[i] == (char) c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	if (!s1 || !s2)
// 		return (NULL);
// 	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	i = -1;
// 	j = 0;
// 	if (s1)
// 		while (s1[++i])
// 			str[i] = s1[i];
// 	while (s2[j])
// 		str[i++] = s2[j++];
// 	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
// 	free(s1);
// 	return (str);
// }
