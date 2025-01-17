/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 17:37:34 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;
	int			i;
	int			index;

	init_data(&data, argc, argv, true);
	ft_printf("Stack before sorting: \n");
	i = 0;
	while (i < data.stack_a.size)
	{
		ft_printf("%i\n", data.stack_a.stack[i]);
		i++;
	}
	/* make sort */
	sort(&data);
	ft_printf("Stack after sort: \n");
	i = 0;
	while (i < data.stack_a.size)
	{
		index = (data.stack_a.top + i) % data.stack_a.size;
		ft_printf("%i\n", data.stack_a.stack[index]);
		i++;
		// ft_printf("%i\n", data.stack_a.stack[i]);
		// i++;
	}
	// rotate_a(&data);
	// ft_printf("Stack after rotate: \n");
	// i = 0;
	// while (i < data.stack_a.size)
	// {
	// 	index = (data.stack_a.top + i) % data.stack_a.size;
	// 	ft_printf("%i\n", data.stack_a.stack[index]);
	// 	i++;
	// }
	// reverse_rotate_a(&data);
	// ft_printf("Stack after reverse rotate: \n");
	// i = 0;
	// while (i < data.stack_a.size)
	// {
	// 	index = (data.stack_a.top + i) % data.stack_a.size;
	// 	ft_printf("%i\n", data.stack_a.stack[index]);
	// 	i++;
	// }
	// swap_a(&data);
	// ft_printf("Stack after swap: \n");
	// i = 0;
	// while (i < data.stack_a.size)
	// {
	// 	index = (data.stack_a.top + i) % data.stack_a.size;
	// 	ft_printf("%i\n", data.stack_a.stack[index]);
	// 	i++;
	// }
	// push_b(&data);
	// ft_printf("Stack A after push: \n");
	// i = 0;
	// while (i < data.stack_a.size)
	// {
	// 	index = (data.stack_a.top + i) % data.stack_a.size;
	// 	if (!data.stack_a.real_zero[index])
	// 		ft_printf("%i\n", data.stack_a.stack[index]);
	// 	i++;
	// }
	// ft_printf("Stack B after push: \n");
	// i = 0;
	// while (i < data.stack_b.size)
	// {
	// 	index = (data.stack_b.top + i) % data.stack_b.size;
	// 	if (data.stack_b.real_zero[index])
	// 		ft_printf("%i\n", data.stack_b.stack[index]);
	// 	i++;
	// }
	/* write operations */
	free_data(&data);
	exit(EXIT_SUCCESS);
}
