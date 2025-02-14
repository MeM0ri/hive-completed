/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:58:14 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/14 18:09:12 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_max_reduction(t_push_swap *data, t_chunk *max)
{
	t_stack	*stack_a;

	stack_a = &data->stack_a;
	if (max->loc == top_a && max->size == 3 && is_consecutive(value(stack_a, 1),
			value(stack_a, 2), value(stack_a, 3), value(stack_a, 4))
		&& a_partly_sort(data, 4))
	{
		//ft_printf("split_max_reduction / if (max->loc == top_a && max->size == 3 && is_consecutive(value(stack_a, 1), value(stack_a, 2), value(stack_a, 3), value(stack_a, 4)) && a_partly_sort(data, 4))");

		sort_three(data, max);
		return ;
	}
	if (max->loc == top_a && value(stack_a, 1) == value(stack_a, 3) - 1
		&& a_partly_sort(data, 3))
	{
		//ft_printf("split_max_reduction / if (max->loc == top_a && value(stack_a, 1) == value(stack_a, 3) - 1 && a_partly_sort(data, 3))\n");

		swap_a(data);
		max->size--;
	}
	if (max->loc == top_a && a_partly_sort(data, 1))
		max->size--;
}

bool	a_partly_sort(t_push_swap *data, int from)
{
	int		i;
	t_stack	*stack_a;
	int		value;

	stack_a = &data->stack_a;
	i = stack_a->top;
	while (--from)
		i = next_index(stack_a, i);
	while (stack_a->stack[i] != data->stack_a.size)
	{
		value = stack_a->stack[i];
		i = next_index(stack_a, i);
		if (stack_a->stack[i] != value + 1)
			return (false);
	}
	return (true);
}

bool	is_consecutive(int a, int b, int c, int d)
{
	sort_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

void	sort_three_numbers(int *a, int *b, int *c)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}
