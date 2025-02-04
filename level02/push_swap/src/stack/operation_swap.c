/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:39:55 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/04 14:39:32 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack_data)
{
	bool	real_zero_tmp;
	int		tmp;
	int		top_index;
	int		next_element_index;

	top_index = stack_data->top;
	next_element_index = next_index(stack_data, top_index);
	if ((stack_data->stack[top_index] == 0
			&& !is_real_zero(stack_data, top_index))
		|| (stack_data->stack[next_element_index] == 0
			&& !is_real_zero(stack_data, next_element_index)))
		return ;
	tmp = stack_data->stack[top_index];
	real_zero_tmp = stack_data->real_zero[top_index];
	stack_data->stack[top_index] = stack_data->stack[next_element_index];
	stack_data->real_zero[top_index]
		= stack_data->real_zero[next_element_index];
	stack_data->stack[next_element_index] = tmp;
	stack_data->real_zero[next_element_index] = real_zero_tmp;
}

void	swap_a(t_push_swap *data)
{
	swap(&data->stack_a);
	if (&data->write_mode)
		fill_operation_list(data, sa);
}

void	swap_b(t_push_swap *data)
{
	swap(&data->stack_b);
	if (&data->write_mode)
		fill_operation_list(data, sb);
}

void	swap_both(t_push_swap *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	if (&data->write_mode)
		fill_operation_list(data, ss);
}
