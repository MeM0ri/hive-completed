/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:23:10 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 14:46:55 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	is_stack_empty(t_stack *stack_data)
{
	if (!stack_data->stack[stack_data->top])
		return (true);
	return (false);
}

bool	is_real_zero(t_stack *stack_data, int index)
{
	if (stack_data->real_zero[index])
		return (true);
	return (false);
}
