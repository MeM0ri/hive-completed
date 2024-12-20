/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:18 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/20 16:50:43 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (buffer);
		buffer++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	char	*newline_prt;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		newline_prt = ft_find_newline(buffer);
		if (newline_prt)
		{

		}
	}
	if (bytes_read < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (line);
}
