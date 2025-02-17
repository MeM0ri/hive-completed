/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 17:55:15 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;
	char		*splitted_args;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		splitted_args = ft_split(argv[1], ' ');
		init_data(&data, argc, &splitted_args, true);
	}
	else
		init_data(&data, argc, argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
