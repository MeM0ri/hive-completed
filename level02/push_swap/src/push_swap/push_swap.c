/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/18 15:11:38 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_splitted_args(char **splitted_args)
{
	int	i;

	i = 0;
	while (splitted_args[i])
	{
		free(splitted_args[i]);
		i++;
	}
	free(splitted_args);
}

int	main(int argc, char **argv)
{
	t_push_swap	data;
	char		**splitted_args;
	int			substr_count;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		splitted_args = ft_split(argv[1], ' ');
		substr_count = 0;
		while (splitted_args[substr_count])
			substr_count++;
		if (!splitted_args)
			exit(EXIT_FAILURE);
		init_data(&data, substr_count, splitted_args, true);
		ft_free_splitted_args(splitted_args);
	}
	else
		init_data(&data, --argc, ++argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
