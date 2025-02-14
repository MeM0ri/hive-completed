/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:49:14 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/14 18:08:51 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_to(t_push_swap *data, t_loc from, t_loc to)
{
	if (from == top_a)
	{
		// ft_printf("move from / call move from top a\n");
		move_from_top_a(data, to);
	}
	else if (from == top_b)
	{
		// ft_printf("move from / call move from top b\n");
		move_from_top_b(data, to);
	}
	else if (from == bottom_a)
	{
		// ft_printf("move from / call move from bottom a\n");
		move_from_bottom_a(data, to);
	}
	else if (from == bottom_b)
	{
		// ft_printf("move from / call move from bottom b\n");
		move_from_bottom_b(data, to);
	}
	return (1);
}

void	move_from_top_a(t_push_swap *data, t_loc to)
{
	if (to == top_b)
	{
		// ft_printf("move from top a to top b\n");
		push_b(data);
	}
	else if (to == bottom_a)
	{
		// ft_printf("move from top a to bottom a\n");
		rotate_a(data);
	}
	else if (to == bottom_b)
	{
		// ft_printf("move from top a to bottom b\n");
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_top_b(t_push_swap *data, t_loc to)
{
	if (to == top_a)
	{
		// ft_printf("move from top b to top a\n");
		push_a(data);
	}
	else if (to == bottom_b)
	{
		// ft_printf("move from top b to bottom b\n");
		rotate_b(data);
	}
	else if (to == bottom_a)
	{
		// ft_printf("move from top b to bottom a\n");
		push_a(data);
		rotate_a(data);
	}
}

void	move_from_bottom_a(t_push_swap *data, t_loc to)
{
	if (to == top_a)
	{
		// ft_printf("move from bottom a to top a\n");
		reverse_rotate_a(data);
	}
	else if (to == top_b)
	{
		// ft_printf("move from bottom a to top b\n");
		reverse_rotate_a(data);
		push_b(data);
	}
	else if (to == bottom_b)
	{
		// ft_printf("move from bottom a to bottom b\n");
		reverse_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_bottom_b(t_push_swap *data, t_loc to)
{
	if (to == top_b)
	{
		// ft_printf("move from bottom b to top b\n");
		reverse_rotate_b(data);
	}
	else if (to == top_a)
	{
		// ft_printf("move from bottom b to top a\n");
		reverse_rotate_b(data);
		push_a(data);
	}
	else if (to == bottom_a)
	{
		// ft_printf("move from bottom b to bottom a\n");
		reverse_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}
