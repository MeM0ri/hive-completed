/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:12:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/19 15:26:53 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "stack.h"

typedef enum e_loc
{
	top_a,
	bottom_a,
	top_b,
	bottom_b
}	t_loc;

typedef struct s_chunk
{
	t_loc	loc;
	int		size;
}	t_chunk;

typedef struct s_split_dest
{
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
}	t_split_dest;

/*-------------------------------MAIN------------------------------------*/
int		main(int argc, char **argv);

/*-------------------------------SORT------------------------------------*/
void	sort(t_push_swap *data);
void	sort_three_a(t_push_swap *data);
void	sort_five_a(t_push_swap *data);

/*----------------------------SORT_UTILS---------------------------------*/
int		find_min_value_index(t_stack *stack_data);
int		find_next_min_value_index(t_stack *stack_data, int min_value_index);

/*----------------------------CHUNK_SORT---------------------------------*/
void	chunk_sort(t_push_swap *data);
void	recursive_chunk_sort(t_push_swap *data, t_chunk *chunk);

/*------------------------CHUNK_SORT_UTILS-------------------------------*/
void	set_chunk_to_top(t_push_swap *data, t_chunk *chunk);
int		find_chunk_max_value(t_push_swap *data, t_chunk *chunk);
t_stack	*loc_to_stack(t_push_swap *data, t_loc loc);

/*---------------------------CHUNK_SPLIT---------------------------------*/
void	chunk_split(t_push_swap *data, t_chunk *chunk,
			t_split_dest *split_dest);
void	set_pivots(t_loc loc, int current_size,
			int *first_pivot, int *second_pivot);

/*------------------------CHUNK_SPLIT_UTILS------------------------------*/
void	set_initial_size(t_chunk *min, t_chunk *mid, t_chunk *max);
void	set_split_loc(t_loc loc,
			t_chunk *min, t_chunk *mid, t_chunk *max);
int		chunk_value(t_push_swap *data, t_chunk *chunk, int n);

/*--------------------------MOVE_OPERATIONS------------------------------*/
int		move_from_to(t_push_swap *data, t_loc from, t_loc to);
void	move_from_top_a(t_push_swap *data, t_loc to);
void	move_from_top_b(t_push_swap *data, t_loc to);
void	move_from_bottom_a(t_push_swap *data, t_loc to);
void	move_from_bottom_b(t_push_swap *data, t_loc to);

/*------------------------SORT_ONE_OPERATIONS----------------------------*/
void	sort_one(t_push_swap *data, t_chunk *chunk);

/*------------------------SORT_TWO_OPERATIONS----------------------------*/
void	sort_two(t_push_swap *data, t_chunk *chunk);

/*-----------------------SORT_THREE_OPERATIONS---------------------------*/
void	sort_three(t_push_swap *data, t_chunk *chunk);
void	sort_three_top_a(t_push_swap *data, t_chunk *chunk,
			t_stack *stack_data, int max);
void	sort_three_top_b(t_push_swap *data, t_chunk *chunk,
			t_stack *stack_data, int max);
void	sort_three_bottom_a(t_push_swap *data, t_chunk *chunk,
			t_stack *stack_data, int max);
void	sort_three_bottom_b(t_push_swap *data, t_chunk *chunk,
			t_stack *stack_data, int max);

/*-----------------------------EASY_SORT---------------------------------*/
void	easy_sort(t_push_swap *data, t_chunk *chunk);
void	easy_sort_second(t_push_swap *data, t_chunk *chunk);
void	handle_top_b(t_push_swap *data, t_chunk *chunk);
void	handle_bottom_a(t_push_swap *data, t_chunk *chunk);
void	handle_bottom_b(t_push_swap *data, t_chunk *chunk);

/*----------------------OPTIMIZATION_OPERATIONS--------------------------*/
void	split_max_reduction(t_push_swap *data, t_chunk *max);
bool	a_partly_sort(t_push_swap *data, int from);
bool	is_consecutive(int a, int b, int c, int d);
void	sort_three_numbers(int *a, int *b, int *c);

/*-----------------POST_SORT_OPTIMIZATION_OPERATIONS---------------------*/
void	post_sort_optimization(t_push_swap *data);
void	eliminate_neutral_op(t_list *op_list);
void	merge_op(t_list *op_list);

/*--------------POST_SORT_OPTIMIZATION_OPERATIONS_UTILS------------------*/
t_s_op	neutral_op(t_s_op op);
bool	op_on_same_stack(t_s_op ref, t_s_op to_check);
t_s_op	child_op(t_s_op first, t_s_op second);
void	remove_op(t_list *to_delete);

#endif
