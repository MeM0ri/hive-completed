/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_one_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:38:08 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/17 16:16:59 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_one(t_push_swap *data, t_chunk *chunk)
{
	if (chunk->loc == bottom_a || chunk->loc == bottom_b
		|| chunk->loc == top_b)
		move_from_to(data, chunk->loc, top_a);
	chunk->size -= 1;
}
