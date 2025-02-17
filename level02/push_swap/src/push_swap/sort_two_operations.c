/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:33:27 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 16:10:09 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == bottom_a || chunk->loc == bottom_b
		|| chunk->loc == top_b)
	{
		move_from_to(data, chunk->loc, top_a);
		move_from_to(data, chunk->loc, top_a);
	}
	if (value(&data->stack_a, 1) > value(&data->stack_a, 2))
		swap_a(data);
	chunk->size -= 2;
}
