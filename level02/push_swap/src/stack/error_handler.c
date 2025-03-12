/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:33:28 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/12 15:29:50 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	error(t_push_swap *data)
{
	if (data)
		free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
