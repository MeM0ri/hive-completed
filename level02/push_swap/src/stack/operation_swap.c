/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:39:55 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/10 16:57:07 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack_data)
{
	int		tmp;
	int		top_index;
	int		next_element_index;

	top_index = stack_data->top;
	next_element_index = next_index(stack_data, top_index);
	if ((stack_data->stack[top_index] == 0)
		|| (stack_data->stack[next_element_index] == 0))
		return ;
	tmp = stack_data->stack[top_index];
	stack_data->stack[top_index] = stack_data->stack[next_element_index];
	stack_data->stack[next_element_index] = tmp;
}

void	swap_a(t_push_swap *data)
{
	swap(&data->stack_a);
	if (data->write_mode)
		fill_operation_list(data, sa);
}

void	swap_b(t_push_swap *data)
{
	swap(&data->stack_b);
	if (data->write_mode)
		fill_operation_list(data, sb);
}

void	swap_both(t_push_swap *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	if (data->write_mode)
		fill_operation_list(data, ss);
}
