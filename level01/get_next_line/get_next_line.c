/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:13:18 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/02 17:37:44 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_newline(char *buffer)
{
	int	i;

	if (!(*buffer))
		return (-1);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

// static char	*update_buffer_storage(char *buffer_storage)
// {
// 	int		i;
// 	int		j;
// 	char	*new_buffer_storage;

// 	i = 0;
// 	while (buffer_storage[i] && buffer_storage[i] != '\n')
// 		i++;
// 	if (!buffer_storage[i])
// 	{
// 		free(buffer_storage);
// 		return (NULL);
// 	}
// 	new_buffer_storage = (char *)malloc(sizeof(char)
// 			* (ft_strlen(buffer_storage) - i + 1));
// 	if (!new_buffer_storage)
// 		return (NULL);
// 	i++;
// 	j = 0;
// 	while (buffer_storage[i])
// 		new_buffer_storage[j++] = buffer_storage[i++];
// 	new_buffer_storage[j] = '\0';
// 	free(buffer_storage);
// 	return (new_buffer_storage);
// }

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;
	int		len;

	if (!(*buffer))
		return (NULL);
	len = ft_find_newline(buffer);
	if (len == -1)
		len = ft_strlen(buffer);
	line = (char *)malloc((len + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

// static char	*extract_line(char *buffer_storage)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	if (!buffer_storage[i])
// 		return (NULL);
// 	while (buffer_storage[i] && buffer_storage[i] != '\n')
// 		i++;
// 	line = (char *)malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (buffer_storage[i] && buffer_storage[i] != '\n')
// 	{
// 		line[i] = buffer_storage[i];
// 		i++;
// 	}
// 	if (buffer_storage[i] == '\n')
// 	{
// 		line[i] = buffer_storage[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

static char	*ft_read_bytes(int fd, char *buffer)
{
	char	*buffer_nl;
	int		bytes_read;

	buffer_nl = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer_nl)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer_nl, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer_nl);
			return (NULL);
		}
		buffer_nl[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, buffer_nl);
	}
	free(buffer_nl);
	return (buffer);
}

// static char	*read_and_store(int fd, char *buffer_storage)
// {
// 	char	*buffer;
// 	int		read_bytes;

// 	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	read_bytes = 1;
// 	while (!ft_strchr(buffer_storage, '\n') && read_bytes != 0)
// 	{
// 		read_bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (read_bytes == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[read_bytes] = '\0';
// 		buffer_storage = ft_strjoin(buffer_storage, buffer);
// 	}
// 	free(buffer);
// 	return (buffer_storage);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_read_bytes(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_update_buffer(buffer);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	static char	*buffer_storage;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buffer_storage = read_and_store(fd, buffer_storage);
// 	if (!buffer_storage)
// 		return (NULL);
// 	line = extract_line(buffer_storage);
// 	buffer_storage = update_buffer_storage(buffer_storage);
// 	return (line);
// }
