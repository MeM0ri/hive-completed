/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:39:55 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/07 13:35:34 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	swap(t_stack *stack_data)
{
	bool	real_zero_tmp;
	int		tmp;
	int		top_index;
	int		next_element_index;

	top_index = stack_data->top;
	next_element_index = next_index(stack_data, top_index);
	if ((stack_data->stack[top_index] == 0
			&& !is_real_zero(stack_data, top_index))
		|| (stack_data->stack[next_element_index] == 0
			&& !is_real_zero(stack_data, next_element_index)))
		return ;
	tmp = stack_data->stack[top_index];
	real_zero_tmp = stack_data->real_zero[top_index];
	stack_data->stack[top_index] = stack_data->stack[next_element_index];
	stack_data->real_zero[top_index]
		= stack_data->real_zero[next_element_index];
	stack_data->stack[next_element_index] = tmp;
	stack_data->real_zero[next_element_index] = real_zero_tmp;
}

void	swap_a(t_push_swap *data)
{
	swap(&data->stack_a);
	ft_printf("%d: sa\n", ++g_calls_counter);
	ft_printf("Stacks after sa: \n");
	print_stacks_for_check(data);
	if (data->write_mode)
		fill_operation_list(data, sa);
}

void	swap_b(t_push_swap *data)
{
	swap(&data->stack_b);
	ft_printf("%d: sb\n", ++g_calls_counter);
	ft_printf("Stacks after sb: \n");
	print_stacks_for_check(data);
	if (data->write_mode)
		fill_operation_list(data, sb);
}

void	swap_both(t_push_swap *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	ft_printf("%d: ss\n", ++g_calls_counter);
	ft_printf("Stacks after ss: \n");
	print_stacks_for_check(data);
	if (data->write_mode)
		fill_operation_list(data, ss);
}
