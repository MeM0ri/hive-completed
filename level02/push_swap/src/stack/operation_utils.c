/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:49:24 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 15:02:27 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_operation_list(t_push_swap *data, enum e_stack_operations e_op)
{
	t_list	*new;

	new = ft_lstnew((void *)e_op);
	if (!new)
		error(data);
	ft_lstadd_back(&data->op_list, new);
}

void	set_real_zero(t_stack *src, t_stack *dest, int src_i, int dest_i)
{
	dest->real_zero[dest_i] = is_real_zero(src, src_i);
}
