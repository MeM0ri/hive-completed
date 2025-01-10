/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:10:54 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/10 15:17:13 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack *create_node(int data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
