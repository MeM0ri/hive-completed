/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:50:09 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/16 16:59:09 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate(t_stack *stack_data)
{
	stack_data->top = next_index(stack_data->stack, stack_data->top);
	stack_data->bottom = next_index(stack_data->stack, stack_data->bottom);
}

void	rotate_a(t_push_swap *data)
{
	rotate(&data->stack_a);
	if (&data->write_mode)
		fill_operation_list(data, ra);
}

void	rotate_b(t_push_swap *data)
{
	rotate(&data->stack_b);
	if (&data->write_mode)
		fill_operation_list(data, rb);
}

void	rotate_both(t_push_swap *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	if (&data->write_mode)
		fill_operation_list(data, rr);
}
