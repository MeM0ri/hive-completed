/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:37:49 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/20 14:45:37 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst)
		return;
	while (*lst)
	{
		temp = (*lst)->next;
		if (del)
			ft_lstdelone(*lst, del);
		else
			free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
