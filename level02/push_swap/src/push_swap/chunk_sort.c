/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:56:18 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/30 17:20:51 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_push_swap *data)
{
	t_chunk	initial_chunk;

	initial_chunk.size = data->stack_a.size;
	initial_chunk.location = top_a;
	recursive_chunk_sort(data, &initial_chunk);

}

void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk)
{
	t_stack_location	stack_location;
}
