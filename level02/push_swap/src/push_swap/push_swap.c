/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/10 15:48:25 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;

	init_data(&data, argc, argv, true);
//	int			i;
//	int			index;
	// ft_printf("Stack before sorting: \n");
	// i = 0;
	// while (i < data.stack_a.size)
	// {
	// 	ft_printf("%i\n", data.stack_a.stack[i]);
	// 	i++;
	// }
	sort(&data);
	// ft_printf("Stack after sort: \n");
	// i = 0;
	// while (i < data.stack_a.size)
	// {
	// 	index = (data.stack_a.top + i) % data.stack_a.size;
	// 	ft_printf("%i\n", data.stack_a.stack[index]);
	// 	i++;
	// }
	free_data(&data);
	exit(EXIT_SUCCESS);
}

int	print_stack(t_push_swap *data)
{
	int			i;
	int			index;

	i = 0;
	ft_printf("Stack A: \n");
	while (i < current_stack_size(&data->stack_a))
	{
		index = (data->stack_a.top + i) % data->stack_a.size;
		ft_printf("%i\n", data->stack_a.stack[index]);
		i++;
	}
	i = 0;
	ft_printf("Stack B: \n");
	while (i < current_stack_size(&data->stack_b))
	{
		index = (data->stack_b.top + i) % data->stack_b.size;
		ft_printf("%i\n", data->stack_b.stack[index]);
		i++;
	}
	return (0);
}
