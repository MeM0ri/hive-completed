/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:46:02 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 16:15:26 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_sort(t_push_swap *data, t_chunk *chunk)
{
	while (chunk->loc != top_a && chunk->size)
	{
		if (value(&data->stack_a, 1) == chunk_value(data, chunk, 1) + 1
			&& chunk->size > 0)
				sort_one(data, chunk);
		else if (value(&data->stack_a, 1) == chunk_value(data, chunk, 2) + 1
			&& chunk->size > 1)
				easy_sort_second(data, chunk);
		else
			break ;
	}
}

void	easy_sort_second(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == top_b)
		handle_top_b(data, chunk);
	else if (chunk->loc == bottom_a)
		handle_bottom_a(data, chunk);
	else if (chunk->loc == bottom_b)
		handle_bottom_b(data, chunk);
	chunk->size--;
}

void	handle_top_b(t_push_swap *data, t_chunk *chunk)
{
	swap_b(data);
	push_a(data);
	if (value(&data->stack_b, 1) == value(&data->stack_a, 1) - 1)
	{;
		push_a(data);
		chunk->size--;
	}
}

void	handle_bottom_a(t_push_swap *data, t_chunk *chunk)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	swap_a(data);
	if (value(&data->stack_a, 1) == value(&data->stack_a, 2) - 1)
		chunk->size--;
	else
		rotate_a(data);
}

void	handle_bottom_b(t_push_swap *data, t_chunk *chunk)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	push_a(data);
	if (value(&data->stack_b, 1) == value(&data->stack_a, 1) - 1)
	{
		push_a(data);
		chunk->size--;
	}
	else
		rotate_b(data);
}
