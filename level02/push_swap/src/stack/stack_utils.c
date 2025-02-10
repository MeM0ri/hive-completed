/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:58:46 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/10 15:07:04 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	next_index(t_stack *stack_data, int index)
{
	if (current_stack_size(stack_data) == 0)
		return (index);
	if (index == stack_data->size - 1)
		return (0);
	return (index + 1);
}

int	prev_index(t_stack *stack_data, int index)
{
	if (current_stack_size(stack_data) == 0)
		return (index);
	if (index == 0)
		return (stack_data->size - 1);
	return (index - 1);
}

int	current_stack_size(t_stack *stack_data)
{
	int	top_i;
	int	bottom_i;

	top_i = stack_data->top;
	bottom_i = stack_data->bottom;
	if (top_i == bottom_i && stack_data->stack[top_i] == 0)
		return (0);
	if (top_i > bottom_i)
		return (stack_data->size - top_i + bottom_i + 1);
	return (bottom_i - top_i + 1);
}

int	value(t_stack *stack_data, int n)
{
	int	i;

	i = stack_data->top;
	while (--n > 0)
		i = next_index(stack_data, i);
	return (stack_data->stack[i]);
}

void	print_stacks_for_check(t_push_swap *data)
{
	int	i = 0;
	int index_a = 0, index_b = 0;
	while (i < data->stack_b.size)
	{
		index_a = (data->stack_a.top + i) % data->stack_a.size;
		index_b = (data->stack_b.top + i) % data->stack_b.size;
		ft_printf("%i\t%i\n", data->stack_a.stack[index_a], data->stack_b.stack[index_b]);
		i++;
	}
}
