/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:49:24 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/10 15:06:54 by alfokin          ###   ########.fr       */
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
