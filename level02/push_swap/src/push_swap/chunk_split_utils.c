/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:12:45 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/04 17:44:38 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_initial_size(t_chunk *min, t_chunk *mid, t_chunk *max)
{
	min->size = 0;
	mid->size = 0;
	max->size = 0;
}

void	set_split_loc(t_loc loc,
			t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (loc == top_a)
	{
		min->loc = bottom_b;
		mid->loc = top_b;
		max->loc = bottom_a;
	}
	else if (loc == bottom_a)
	{
		min->loc = bottom_b;
		mid->loc = top_b;
		max->loc = top_a;
	}
	else if (loc == top_b)
	{
		min->loc = bottom_b;
		mid->loc = bottom_a;
		max->loc = top_a;
	}
	else if (loc == bottom_b)
	{
		min->loc = top_b;
		mid->loc = bottom_a;
		max->loc = top_a;
	}
}

int	chunk_value(t_push_swap *data, t_chunk *chunk, int n)
{
	t_loc	loc;
	t_stack	*stack_data;
	int		i;

	loc = chunk->loc;
	stack_data = loc_to_stack(data, loc);
	if (loc == top_a || loc == top_b)
		i = stack_data->top;
	else if (loc == bottom_a || loc == bottom_b)
		i = stack_data->bottom;
	if (loc == top_a || loc == top_b)
		while (--n > 0)
			i = next_index(stack_data, i);
	else if (loc == bottom_a || loc == bottom_b)
		while (--n > 0)
			i = prev_index(stack_data, i);
	return (stack_data->stack[i]);
}
