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
		return ;
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
