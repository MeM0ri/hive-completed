/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:49:14 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 16:18:52 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_to(t_push_swap *data, t_loc from, t_loc to)
{
	if (from == top_a)
		move_from_top_a(data, to);
	else if (from == top_b)
		move_from_top_b(data, to);
	else if (from == bottom_a)
		move_from_bottom_a(data, to);
	else if (from == bottom_b)
		move_from_bottom_b(data, to);
	return (1);
}

void	move_from_top_a(t_push_swap *data, t_loc to)
{
	if (to == top_b)
		push_b(data);
	else if (to == bottom_a)
		rotate_a(data);
	else if (to == bottom_b)
	{
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_top_b(t_push_swap *data, t_loc to)
{
	if (to == top_a)
		push_a(data);
	else if (to == bottom_b)
		rotate_b(data);
	else if (to == bottom_a)
	{
		push_a(data);
		rotate_a(data);
	}
}

void	move_from_bottom_a(t_push_swap *data, t_loc to)
{
	if (to == top_a)
		reverse_rotate_a(data);
	else if (to == top_b)
	{
		reverse_rotate_a(data);
		push_b(data);
	}
	else if (to == bottom_b)
	{
		reverse_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_bottom_b(t_push_swap *data, t_loc to)
{
	if (to == top_b)
		reverse_rotate_b(data);
	else if (to == top_a)
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	else if (to == bottom_a)
	{
		reverse_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}
