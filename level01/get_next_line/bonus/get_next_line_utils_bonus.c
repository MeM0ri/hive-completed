/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:50 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/30 16:30:27 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*new_line;
	int		new_line_len;
	int		buffer_len;
	int		line_len;

	if (!line && !buffer)
		return (NULL);
	buffer_len = ft_strlen(buffer);
	line_len = ft_strlen(line);
	new_line_len = buffer_len + line_len;
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
