/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/05 16:10:55 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdio.h>

int	has_cycle(t_list *lst)
{
	t_list	*slow = lst;
	t_list	*fast = lst;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		//printf("Checking nodes: slow=%p, fast=%p\n", slow, fast);
		if (slow == fast)
		{
			//printf("Cycle detected\n");
			return (1); // Cycle detected
		}
	}
	//printf("No cycle detected\n");
	return (0); // No cycle
}

t_list	*ft_lstlast(t_list *lst)
{
	if (has_cycle(lst))
	{
		//printf("Cycle detected in the list\n");
		return (NULL);
	}
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		//printf("Current node: %p, Next node: %p\n", lst, lst->next); // Debug print
		lst = lst->next;
	}
	return (lst);
}
