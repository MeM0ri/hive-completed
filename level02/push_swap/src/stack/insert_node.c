/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:15:48 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/10 15:17:13 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	insert_node(t_stack **node, int data)
{
	t_stack *new_node;
	t_stack *tmp;

	new_node = create_node(data);
	if (!new_node)
		return ;
	if (*node == NULL)
	{
		*node = new_node;
		return ;
	}
	tmp = *node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
}
