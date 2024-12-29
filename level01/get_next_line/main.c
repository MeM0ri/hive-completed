/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:26:54 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/23 16:34:15 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("Please provide ONE file to read from.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open provided file.\n");
		return (1);
	}
	//line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		//line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
