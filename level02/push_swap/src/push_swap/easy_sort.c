/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:46:02 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/14 18:07:43 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	easy_sort(t_push_swap *data, t_chunk *chunk)
{
	while (chunk->loc != top_a && chunk->size)
	{
		if (value(&data->stack_a, 1) == chunk_value(data, chunk, 1) + 1
			&& chunk->size > 0)
			{
				// ft_printf("Easy sort one.\n");
				sort_one(data, chunk);
			}
		else if (value(&data->stack_a, 1) == chunk_value(data, chunk, 2) + 1
			&& chunk->size > 1)
			{
				// ft_printf("Easy sort second.\n");
				easy_sort_second(data, chunk);
			}
		else
		{
			// ft_printf("Easy sort break.\n");
			break ;
		}
	}
}

void	easy_sort_second(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == top_b)
	{
		// ft_printf("Easy sort / handle top b\n");
		handle_top_b(data, chunk);
	}
	else if (chunk->loc == bottom_a)
	{
		// ft_printf("Easy sort / handle bottom a\n");
		handle_bottom_a(data, chunk);
	}
	else if (chunk->loc == bottom_b)
	{
		// ft_printf("Easy sort / handle bottom b\n");
		handle_bottom_b(data, chunk);
	}
	chunk->size--;
}

void	handle_top_b(t_push_swap *data, t_chunk *chunk)
{
	swap_b(data);
	push_a(data);
	// ft_printf("handle top b\n");
	if (value(&data->stack_b, 1) == value(&data->stack_a, 1) - 1)
	{
		// ft_printf("handle top a / inside if\n");
		push_a(data);
		chunk->size--;
	}
}

void	handle_bottom_a(t_push_swap *data, t_chunk *chunk)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	swap_a(data);
	// ft_printf("handle bottom a\n");
	if (value(&data->stack_a, 1) == value(&data->stack_a, 2) - 1)
	{
		// ft_printf("handle bottom a / inside if\n");
		chunk->size--;
	}
	else
	{
		// ft_printf("handle bottom a / inside else\n");
		rotate_a(data);
	}
}

void	handle_bottom_b(t_push_swap *data, t_chunk *chunk)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	push_a(data);
	// ft_printf("handle bottom b\n");
	if (value(&data->stack_b, 1) == value(&data->stack_a, 1) - 1)
	{
		// ft_printf("handle bottom b / inside if\n");
		push_a(data);
		chunk->size--;
	}
	else
	{
		// ft_printf("handle bottom b / inside else\n");
		rotate_b(data);
	}
}
