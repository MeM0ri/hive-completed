/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:46:02 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/10 16:05:09 by alfokin          ###   ########.fr       */
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
			ft_printf("easy_sort in if\n");
			sort_one(data, chunk);
		}
		else if (value(&data->stack_a, 1) == chunk_value(data, chunk, 2) + 1
			&& chunk->size > 1)
		{
			ft_printf("easy_sort in else if\n");
			easy_sort_second(data, chunk);
		}
		else
			break ;
	}
}

void	easy_sort_second(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == top_b)
	{
		ft_printf("easy_sort_second in if\n");
		handle_top_b(data, chunk);
	}
	else if (chunk->loc == bottom_a)
	{
		ft_printf("easy_sort_second in else if\n");
		handle_bottom_a(data, chunk);
	}
	else if (chunk->loc == bottom_b)
	{
		ft_printf("easy_sort_second in second else if\n");
		handle_bottom_b(data, chunk);
	}
	chunk->size--;
}

void	handle_top_b(t_push_swap *data, t_chunk *chunk)
{
	swap_b(data);
	push_a(data);
	ft_printf("handle_top_b\n");
	if (value(&data->stack_b, 1) == value(&data->stack_a, 1) - 1)
	{
		push_a(data);
		ft_printf("handle_top_b in if\n");
		chunk->size--;
	}
}

void	handle_bottom_a(t_push_swap *data, t_chunk *chunk)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	swap_a(data);
	ft_printf("handle_bottom_a\n");
	if (value(&data->stack_a, 1) == value(&data->stack_a, 2) - 1)
	{
		ft_printf("handle_bottom_a in if\n");
		chunk->size--;
	}
	else
	{
		ft_printf("handle_bottom_a in else\n");
		rotate_a(data);
	}
}

void	handle_bottom_b(t_push_swap *data, t_chunk *chunk)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	push_a(data);
	ft_printf("handle_bottom_b\n");
	if (value(&data->stack_b, 1) == value(&data->stack_a, 1) - 1)
	{
		push_a(data);
		ft_printf("handle_bottom_b in if\n");
		chunk->size--;
	}
	else
	{
		ft_printf("handle_bottom_a in else\n");
		rotate_b(data);
	}
}
