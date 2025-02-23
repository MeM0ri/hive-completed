/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:25:58 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/23 21:58:38 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	free_data(t_push_swap *data)
{
	if (data->stack_a.stack)
		free(data->stack_a.stack);
	if (data->stack_b.stack)
		free(data->stack_b.stack);
	if (data->op_list)
		ft_lstclear(&data->op_list, NULL);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
