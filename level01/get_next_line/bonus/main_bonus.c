/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:26:54 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/03 14:58:45 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	printRandoms(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

int main(int argc, char **argv)
{
	int		fd[argc];
	char	*line;
	int		test;
	int		file_num;
	int		i;

	if (argc < 2)
	{
		printf("Please provide AT LEAST one file to read from.\n");
		return (1);
	}

	i = 0;
	while (i < argc - 1)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] < 0)
		{
			printf("Error: Could not open provided file. Number of file: %i\n", i);
			return (1);
		}
		i++;
	}

	//----------------------------------------Simple Looped Test-----------------------------------------//
	i = 0;
	line = get_next_line(fd[i]);
	while (line)
	{
		printf("%s", line);
		free(line);
		i++;
		if (i > 3)
			i = 0;
		line = get_next_line(fd[i]);
	}

	//----------------------------------------Simple Test-----------------------------------------//
	// line = get_next_line(fd[0]);
	// printf("First Line of text_file_1.txt: %s", line);
	// free(line);

	// line = get_next_line(fd[1]);
	// printf("First Line of text_file_2.txt: %s", line);
	// free(line);

	// line = get_next_line(fd[0]);
	// printf("Second Line of text_file_1.txt: %s", line);
	// free(line);

	// line = get_next_line(fd[2]);
	// printf("First Line of text_file_3.txt: %s", line);
	// free(line);

	// line = get_next_line(fd[0]);
	// printf("Third Line of text_file_1.txt: %s", line);
	// free(line);

	// line = get_next_line(fd[3]);
	// printf("First Line of kitty.jpeg: %s", line);
	// free(line);

	//----------------------------------------Randomly Looped Test-----------------------------------------//
	// 	srand(time(0));
	// 	file_num = printRandoms(0, argc - 1);
	// 	line = get_next_line(fd[file_num]);
	// 	while (line)
	// 	{
	// 		printf("%i\n", file_num);
	// 		printf("%s", line);
	// 		file_num = printRandoms(0, argc - 1);
	// 		free(line);
	// 		line = get_next_line(fd[file_num]);
	// 	}

	while (i < argc)
	{
		close(fd[i]);
		i++;
	}
	return (0);
}
