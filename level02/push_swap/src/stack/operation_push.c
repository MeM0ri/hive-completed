/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:52:58 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/10 16:57:19 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_new_top;

	dest_new_top = prev_index(dest, dest->top);
	dest->stack[dest_new_top] = src->stack[src->top];
	dest->top = dest_new_top;
	src->stack[src->top] = 0;
	src->top = next_index(src, src->top);
}

void	push_a(t_push_swap *data)
{
	push(&data->stack_b, &data->stack_a);
	if (data->write_mode)
		fill_operation_list(data, pa);
}

void	push_b(t_push_swap *data)
{
	push(&data->stack_a, &data->stack_b);
	if (data->write_mode)
		fill_operation_list(data, pb);
}
