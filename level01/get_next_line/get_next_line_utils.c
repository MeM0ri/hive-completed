/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:50 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/26 15:23:08 by alfokin          ###   ########.fr       */
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

int		ft_strlen(char *str)
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
	int		i;

	new_line_len = ft_strlen(line) + ft_strlen(buffer);
	new_line = (char *)malloc(sizeof(char) * (new_line_len + 1));
	i = 0;
	if (!new_line)
		return NULL;
	ft_strcpy(line, new_line, 0);
	ft_strcpy(buffer, new_line, ft_strlen(line));
	new_line[new_line_len] = '\0';
	return (new_line);
}
