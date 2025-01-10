/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:10:54 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/10 16:44:19 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	init_data(t_push_swap *data, int stack_size, char **values, bool write_mode)
{
	stack_size--;
	init_stack(data, &data->stack_a, stack_size);
	init_stack(data, &data->stack_b, stack_size);
}

void	init_stack(t_push_swap *data, t_stack *stack_data, int stack_size)
{
	stack_data->stack = malloc(stack_size + sizeof(int));
	if (!stack_data->stack)
		error(data);
	stack_data->top = 0;
	stack_data->bottom = 0;
	stack_data->size = stack_size;
}

void	error(t_push_swap *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
