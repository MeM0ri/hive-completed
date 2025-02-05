/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:45:28 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/05 15:19:02 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_chunk_to_top(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == bottom_b
		&& current_stack_size(&data->stack_b) == chunk->size)
		chunk->loc = top_b;
	else if (chunk->loc == bottom_a
		&& current_stack_size(&data->stack_a) == chunk->size)
		chunk->loc = top_a;
}

int	find_chunk_max_value(t_push_swap *data, t_chunk *chunk)
{
	t_stack	*stack_data;
	int		max_value;
	int		chunk_size;
	int		index;

	stack_data = loc_to_stack(data, chunk->loc);
	chunk_size = chunk->size;
	max_value = INT_MIN;
	if (chunk->loc == top_a || chunk->loc == top_b)
		index = stack_data->top;
	else
		index = stack_data->bottom;
	while (chunk_size--)
	{
		if (stack_data->stack[index] > max_value)
			max_value = stack_data->stack[index];
		index = next_index(stack_data, index);
	}
	return (max_value);
}

t_stack	*loc_to_stack(t_push_swap *data, t_loc loc)
{
	if (loc == top_a || loc == bottom_a)
		return (&data->stack_a);
	else
		return (&data->stack_b);
}
