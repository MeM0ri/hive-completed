/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:49:24 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/19 18:16:39 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	fill_operation_list(t_push_swap *data, t_s_op e_op)
{
	t_list	*new;

	new = ft_lstnew((void *)e_op);
	if (!new)
		error(data);
	ft_lstadd_back(&data->op_list, new);
}

void	print_operations(t_list *head)
{
	t_list	*reader;

	reader = head;
	while (reader)
	{
		ft_printf("%s\n", op_to_string(op_from(reader)));
		reader = reader->next;
	}
}

const char	*op_to_string(t_s_op e_op)
{
	static const char	*strings[12];

	strings[0] = "null_op";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "sa";
	strings[4] = "sb";
	strings[5] = "ss";
	strings[6] = "ra";
	strings[7] = "rb";
	strings[8] = "rr";
	strings[9] = "rra";
	strings[10] = "rrb";
	strings[11] = "rrr";
	return (strings[e_op]);
}

t_s_op	op_from(t_list *node)
{
	return ((t_s_op)(uintptr_t)node->content);
}
