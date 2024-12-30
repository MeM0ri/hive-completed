/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:18 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/30 16:49:21 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	ft_buffer_parse(char **buffer, char **newline_ptr)
{
	char	*temp;
	int		i;

	temp = ft_strdup(*newline_ptr);
	if (!temp)
		return ; // CHECK FREE *buffer[1024]
	i = 0;
	while ((*buffer)[i] != **newline_ptr)
		i++;
	(*buffer)[++i] = '\0';
	temp++;
	*newline_ptr = temp;
}

void	ft_read_bytes(int fd, char **buffer, char **line, int *bytes_read)
{
	char	*newline_ptr;

	while (*bytes_read > 0)
	{
		(*buffer)[*bytes_read] = '\0';
		newline_ptr = ft_find_newline(*buffer);
		if (newline_ptr)
		{
			ft_buffer_parse(buffer, &newline_ptr);
			*line = ft_strjoin(*line, *buffer);
			*buffer = newline_ptr;
			return ;
		}
		*line = ft_strjoin(*line, *buffer);
		*bytes_read = read(fd, *buffer, BUFFER_SIZE);
	}
	// if (*bytes_read < 1) // CHECK
	// 	{ }
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*newline_ptr;
	int			bytes_read;

	// bytes_read GARBAGE
	if (BUFFER_SIZE <= 0 || fd < 0) // MAX INT FOR BUFFER
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer[fd])
			return (NULL); // CHECK FREE *buffer[1024]
		buffer[fd][0] = '\0';
		bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
	}
	bytes_read = ft_strlen(buffer[fd]);
	line = NULL;
	ft_read_bytes(fd, &buffer[fd], &line, &bytes_read);
	return (line);
}
