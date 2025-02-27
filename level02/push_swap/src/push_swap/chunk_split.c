/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:09:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 16:07:51 by alfokin          ###   ########.fr       */
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
	set_pivots(chunk->loc, chunk->size, &first_pivot, &second_pivot);
	max_value = find_chunk_max_value(data, chunk);
	while (chunk->size > 0)
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
		chunk->size--;
	}
}

void	set_pivots(t_loc location, int current_size,
			int *first_pivot, int *second_pivot)
{
	*second_pivot = current_size / 3;
	*first_pivot = 0;
	if (location == top_a || location == bottom_a)
		*first_pivot = 2 * current_size / 3;
	if (location == top_b || location == bottom_b)
		*first_pivot = current_size / 2;
	if ((location == top_a || location == bottom_a) && current_size < 15)
		*first_pivot = current_size;
	if (location == bottom_b && current_size < 8)
		*second_pivot = current_size / 2;
}
