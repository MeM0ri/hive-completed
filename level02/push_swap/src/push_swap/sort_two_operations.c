/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:33:27 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/14 18:10:34 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == bottom_a || chunk->loc == bottom_b
		|| chunk->loc == top_b)
	{
		// ft_printf("sort two / if (chunk->loc == bottom_a || chunk->loc == bottom_b || chunk->loc == top_b)\n");

		move_from_to(data, chunk->loc, top_a);
		move_from_to(data, chunk->loc, top_a);
	}
	if (value(&data->stack_a, 1) > value(&data->stack_a, 2))
	{
		// ft_printf("sort two / if (value(&data->stack_a, 1) > value(&data->stack_a, 2))\n");

		swap_a(data);
	}
	chunk->size -= 2;
}
