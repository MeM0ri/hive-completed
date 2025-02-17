/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:20:58 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 16:09:51 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_push_swap *data, t_chunk *chunk)
{
	t_stack	*stack_data;
	int		max;


	stack_data = loc_to_stack(data, chunk->loc);
	max = find_chunk_max_value(data, chunk);
	if (chunk->loc == top_a)
		sort_three_top_a(data, chunk, stack_data, max);
	else if (chunk->loc == bottom_a)
		sort_three_bottom_a(data, chunk, stack_data, max);
	else if (chunk->loc == top_b)
		sort_three_top_b(data, chunk, stack_data, max);
	else if (chunk->loc == bottom_b)
		sort_three_bottom_b(data, chunk, stack_data, max);
}

void	sort_three_top_a(t_push_swap *data, t_chunk *chunk,
		t_stack *stack_data, int max)
{
	if (stack_data->stack[stack_data->top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
		if (stack_data->stack[next_index(stack_data, stack_data->top)] > stack_data->stack[stack_data->top])
			swap_a(data);
	}
	else if (stack_data->stack[next_index(stack_data, stack_data->top)]
		== max)
	{
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	chunk->loc = top_a;
	chunk->size -= 1;
	sort_two(data, chunk);
}

void	sort_three_top_b(t_push_swap *data, t_chunk *chunk,
		t_stack *stack_data, int max)
{
	push_a(data);
	if (stack_data->stack[stack_data->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (stack_data->stack[next_index(stack_data, stack_data->top)]
		== max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
		push_a(data);
	push_a(data);
	chunk->loc = top_a;
	chunk->size -= 1;
	sort_two(data, chunk);
}

void	sort_three_bottom_a(t_push_swap *data, t_chunk *chunk,
		t_stack *stack_data, int max)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	if (stack_data->stack[stack_data->top] == max)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (stack_data->stack[next_index(stack_data, stack_data->top)]
		== max)
		reverse_rotate_a(data);
	else
	{
		push_b(data);
		reverse_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	chunk->loc = top_a;
	chunk->size -= 1;
	sort_two(data, chunk);
}

void	sort_three_bottom_b(t_push_swap *data, t_chunk *chunk,
		t_stack *stack_data, int max)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	if (stack_data->stack[stack_data->top] == max)
	{
		push_a(data);
		reverse_rotate_b(data);
	}
	else if (stack_data->stack[next_index(stack_data, stack_data->top)]
		== max)
	{
		swap_b(data);
		push_a(data);
		reverse_rotate_b(data);
	}
	else
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	chunk->loc = top_b;
	chunk->size -= 1;
	sort_two(data, chunk);
}
