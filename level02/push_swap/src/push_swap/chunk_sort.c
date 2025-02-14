/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:56:18 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/14 18:05:13 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_push_swap *data)
{
	t_chunk	initial_chunk;

	initial_chunk.size = data->stack_a.size;
	initial_chunk.loc = top_a;
	recursive_chunk_sort(data, &initial_chunk);
}

void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk)
{
	t_split_dest	split_dest;

	set_chunk_to_top(data, chunk);
	easy_sort(data, chunk);
	if (chunk->size <= 3)
	{
		//ft_printf("recursive_chunk_sort / if (chunk->size <= 3) \n");

		if (chunk->size == 3)
		{
			//ft_printf("recursive_chunk_sort / if (chunk->size == 3) \n");

			sort_three(data, chunk);
		}
		else if (chunk->size == 2)
		{
			//ft_printf("recursive_chunk_sort / else if (chunk->size == 2) \n");

			sort_two(data, chunk);
		}
		// else
		// {
		// 	ft_printf("recursive_chunk_sort / else \n");

		// 	sort_one(data, chunk);
		// }
		return ;
	}
	chunk_split(data, chunk, &split_dest);
	recursive_chunk_sort(data, &split_dest.max);
	recursive_chunk_sort(data, &split_dest.mid);
	recursive_chunk_sort(data, &split_dest.min);
}
