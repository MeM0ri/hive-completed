/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 15:13:13 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;
	int			i;

	init_data(&data, argc, argv, true);
	ft_printf("Stack before sorting: \n");
	i = 0;
	while (i < data.stack_a.size)
	{
		ft_printf("%i\n", data.stack_a.stack[i]);
		i++;
	}
	/* make sort */
	ft_printf("Stack after sorting: \n");
	i = 0;
	while (i < data.stack_a.size)
	{
		ft_printf("%i\n", data.stack_a.stack[i]);
		i++;
	}
	/* write operations */
	free_data(&data);
	exit(EXIT_SUCCESS);
}
