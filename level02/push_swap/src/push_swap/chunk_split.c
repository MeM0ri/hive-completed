/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/05 15:07:31 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_split(t_push_swap *data, t_chunk *chunk, t_split_dest *dest)
{
	int	first_pivot;
	int	second_pivot;
	int	max_value;
	int	next_value;

	set_initial_size(&dest->min, &dest->mid, &dest->max);
	set_split_loc(chunk->loc, &dest->min, &dest->mid, &dest->max);
	set_pivots(data, &first_pivot, &second_pivot);
	max_value = find_chunk_max_value(data, chunk);
	while (chunk->size--)
	{
		next_value = chunk_value(data, chunk, 1);
		if (next_value > max_value - second_pivot)
		{
			dest->max.size += move_from_to(data, chunk->loc, dest->max.loc);
			split_max_reduction(data, &dest->max);
			if (a_partly_sort(data, 1) && chunk->size)
				easy_sort(data, chunk);
		}
		else if (next_value > max_value - first_pivot)
			dest->mid.size += move_from_to(data, chunk->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, chunk->loc, dest->min.loc);
	}
}

void	set_pivots(t_push_swap *data, int *first_pivot, int *second_pivot)
{
	if (&data->stack_a.stack && current_stack_size(&data->stack_a) > 1)
	{
		*first_pivot = data->stack_a.stack[data->stack_a.top];
		*second_pivot = data->stack_a.stack[data->stack_a.bottom];
	}
	else if (&data->stack_a.stack
		&& current_stack_size(&data->stack_a) == 1)
	{
		*first_pivot = data->stack_a.stack[data->stack_a.top];
		*second_pivot = data->stack_b.stack[data->stack_b.top];
	}
	else
	{
		*first_pivot = data->stack_a.stack[data->stack_b.top];
		*second_pivot = data->stack_b.stack[data->stack_b.bottom];
	}
}
