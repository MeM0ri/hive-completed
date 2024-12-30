/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:26:54 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/30 15:25:30 by alfokin          ###   ########.fr       */
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
	int		fd[3];
	char	*line;
	int		test;
	int		file_num;

	if (argc < 2)
	{
		printf("Please provide AT LEAST one file to read from.\n");
		return (1);
	}

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_RDONLY);
	fd[2] = open(argv[3], O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0)
	{
		printf("Error: Could not open provided file.\n");
		return (1);
	}

	test = 1;
	switch (test)
	{
		case 0:
			line = get_next_line(fd[0]);
			printf("%s", line);
			free(line);

			line = get_next_line(fd[1]);
			printf("%s", line);
			free(line);

			line = get_next_line(fd[0]);
			printf("%s", line);
			free(line);

			line = get_next_line(fd[2]);
			printf("%s", line);
			free(line);

			line = get_next_line(fd[0]);
			printf("%s", line);
			free(line);
			break;

		default:
			srand(time(0));
			file_num = printRandoms(0, 2);
			while (*(line = get_next_line(fd[file_num])) != '\0')
			{
				printf("%i\n", file_num);
				printf("%s", line);
				file_num = printRandoms(0, 2);
				free(line);
			}
			break;
	}

	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}
