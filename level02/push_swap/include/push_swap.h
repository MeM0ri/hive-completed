/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:12:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/30 17:20:45 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "stack.h"

typedef enum e_locations
{
	top_a,
	bottom_a,
	top_b,
	bottom_b
}	t_locations;

typedef struct s_chunk
{
	t_locations	location;
	int			size;
}	t_chunk;

typedef struct s_stack_location
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}	t_stack_location;

/*-------------------------------MAIN------------------------------------*/
int		main(int argc, char **argv);
int		print_stack(t_push_swap *data);

/*-------------------------------SORT------------------------------------*/
void	sort(t_push_swap *data);
void	sort_three_a(t_push_swap *data);
void	sort_five_a(t_push_swap *data);

/*----------------------------SORT_UTILS---------------------------------*/
bool	is_sorted(t_stack *stack_data);
int		find_min_value_index(t_stack *stack_data);
int		find_next_min_value_index(t_stack *stack_data, int min_value_index);

/*----------------------------SORT_UTILS---------------------------------*/
void	chunk_sort(t_push_swap *data);
void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk);

#endif
