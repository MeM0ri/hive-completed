/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:28:11 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 17:39:18 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push_swap *data)
{
	if (is_sorted(&data->stack_a))
		return ;
	else if (data->stack_a.size == 3)
		sort_three_a(data);
	return ;
}

void	sort_three_a(t_push_swap *data)
{
	t_stack	*stack_data;
	int		first;
	int		second;
	int		third;

	stack_data = &data->stack_a;
	first = stack_data->stack[stack_data->top];
	second = stack_data->stack[next_index(stack_data, stack_data->top)];
	third = stack_data->stack[stack_data->bottom];
	if (first > second && second > third)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (first < second && second > third && third > first)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (first < second && third < first)
		reverse_rotate_a(data);
	else if (first > second && second < third && third < first)
		rotate_a(data);
	else if (first > second && third > first)
		swap_a(data);
}
