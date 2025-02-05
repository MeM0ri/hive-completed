/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:28:11 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/05 15:21:12 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_push_swap *data)
{
	if (is_sorted(&data->stack_a))
		return ;
	else if (data->stack_a.size == 3)
		sort_three_a(data);
	else if (data->stack_a.size == 5)
		sort_five_a(data);
	else
		chunk_sort(data);
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

void	sort_five_a(t_push_swap *data)
{
	int	first_index;
	int	second_index;

	first_index = find_min_value_index(&data->stack_a);
	second_index = find_next_min_value_index(&data->stack_a, first_index);
	while (current_stack_size(&data->stack_a) > 3)
	{
		if (data->stack_a.top == first_index
			|| data->stack_a.top == second_index)
			push_b(data);
		else
			rotate_a(data);
	}
	if (data->stack_b.stack[data->stack_b.top]
		< data->stack_b.stack[data->stack_b.bottom])
		swap_b(data);
	sort_three_a(data);
	push_a(data);
	push_a(data);
}
