/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:31:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 16:43:30 by alfokin          ###   ########.fr       */
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
