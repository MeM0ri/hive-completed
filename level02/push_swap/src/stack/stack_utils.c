/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:58:46 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/27 16:22:31 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int next_index(t_stack *stack_data, int index)
{
	if (current_stack_size(stack_data) == 0)
		return (index);
	if (index == stack_data->size - 1)
		return (0);
	return (index + 1);
}

int prev_index(t_stack *stack_data, int index)
{
	if (current_stack_size(stack_data) == 0)
		return (index);
	if (index == 0)
		return (stack_data->size - 1);
	return (index - 1);
}

int current_stack_size(t_stack *stack_data)
{
	int top_i;
	int bottom_i;

	top_i = stack_data->top;
	bottom_i = stack_data->bottom;
	if (top_i == bottom_i && stack_data->stack[top_i] == 0
		&& !is_real_zero(stack_data, top_i))
		return (0);
	if (top_i > bottom_i)
		return (stack_data->size - top_i + bottom_i + 1);
	return (bottom_i - top_i + 1);
}
