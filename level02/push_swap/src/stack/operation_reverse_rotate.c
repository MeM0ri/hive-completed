/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:57:25 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 17:38:56 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	reverse_rotate(t_stack *stack_data)
{
	stack_data->top = prev_index(stack_data, stack_data->top);
	stack_data->bottom = prev_index(stack_data, stack_data->bottom);
}

void	reverse_rotate_a(t_push_swap *data)
{
	reverse_rotate(&data->stack_a);
	if (&data->write_mode)
		fill_operation_list(data, rra);
}

void	reverse_rotate_b(t_push_swap *data)
{
	reverse_rotate(&data->stack_b);
	if (&data->write_mode)
		fill_operation_list(data, rrb);
}

void	reverse_rotate_both(t_push_swap *data)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	if (&data->write_mode)
		fill_operation_list(data, rrr);
}
