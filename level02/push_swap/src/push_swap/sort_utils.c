/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:31:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/04 14:40:46 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack_data)
{
	int	i;
	int	j;

	i = stack_data->top;
	j = 0;
	while (j < stack_data->size)
	{
		if (stack_data->stack[i] > stack_data->stack[next_index(stack_data, i)])
			return (false);
		i = next_index(stack_data, i);
		j++;
	}
	return (true);
}

int	find_min_value_index(t_stack *stack_data)
{
	int	i;
	int	min_value_index;

	i = stack_data->top;
	min_value_index = i;
	while (i != stack_data->bottom)
	{
		if (stack_data->stack[min_value_index] > stack_data->stack[i])
			min_value_index = i;
		i = next_index(stack_data, i);
	}
	if (stack_data->stack[min_value_index] > stack_data->stack[i])
		min_value_index = i;
	return (min_value_index);
}

int	find_next_min_value_index(t_stack *stack_data, int min_value_index)
{
	int	i;
	int	next_min_value_index;

	i = stack_data->top;
	next_min_value_index = i;
	while (i != stack_data->bottom)
	{
		if ((stack_data->stack[next_min_value_index] > stack_data->stack[i])
			&& (stack_data->stack[i] > stack_data->stack[min_value_index]))
			next_min_value_index = i;
		i = next_index(stack_data, i);
	}
	if ((stack_data->stack[next_min_value_index] > stack_data->stack[i])
		&& (stack_data->stack[i] > stack_data->stack[min_value_index]))
		next_min_value_index = i;
	return (next_min_value_index);
}
