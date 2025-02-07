/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:52:58 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/07 17:15:14 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_new_top;

	if (is_stack_empty(src))
		return ;
	dest_new_top = prev_index(dest, dest->top);
	dest->stack[dest_new_top] = src->stack[src->top];
	dest->top = dest_new_top;
	set_real_zero(src, dest, src->top, dest->top);
	src->stack[src->top] = 0;
	src->real_zero[src->top] = false;
	src->top = next_index(src, src->top);
}

void	push_a(t_push_swap *data)
{
	push(&data->stack_b, &data->stack_a);
	ft_printf("pa\n");
	//ft_printf("%d: pa\n", ++g_calls_counter);
	// ft_printf("Stacks after pa: \n");
	// print_stacks_for_check(data);
	if (data->write_mode)
		fill_operation_list(data, pa);
}

void	push_b(t_push_swap *data)
{
	push(&data->stack_a, &data->stack_b);
	ft_printf("pb\n");
	// ft_printf("%d: pb\n", ++g_calls_counter);
	// ft_printf("Stacks after pb: \n");
	// print_stacks_for_check(data);
	if (data->write_mode)
		fill_operation_list(data, pb);
}
