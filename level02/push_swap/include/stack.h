/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:01 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/23 19:29:46 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/*-------------------------STACK STRUCTURE------------------------------*/
typedef struct s_stack
{
	int		*stack;
	int		size;
	int		top;
	int		bottom;
}	t_stack;

typedef struct s_push_swap
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*op_list;
	bool	write_mode;
}	t_push_swap;

typedef enum e_stack_operations
{
	null_op,
	pa,
	pb,
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_s_op;

/*----------------------------INIT UTILS---------------------------------*/
void		init_data(t_push_swap *data, int argc,
				char **argv, bool write_mode);
void		init_stack(t_push_swap *data, t_stack *stack_data, int stack_size);
void		fill_stack(t_push_swap *data, t_stack *stack_data, int stack_size,
				char **values);

/*----------------------------INIT_CHECKS--------------------------------*/
bool		is_valid_value(char *value);
void		is_duplicates(t_push_swap *data, int *numbers, int stack_size);

/*----------------------------STACK_UTILS--------------------------------*/
int			next_index(t_stack *stack_data, int index);
int			prev_index(t_stack *stack_data, int index);
int			current_stack_size(t_stack *stack_data);
int			value(t_stack *stack_data, int n);
bool		is_sorted(t_stack *stack_data);

/*--------------------------ERROR_HANDLER--------------------------------*/
void		error(t_push_swap *data);

/*----------------------------FREE_DATA----------------------------------*/
void		free_data(t_push_swap *data);
void		ft_free_array(char **array);

/*-------------------------OPERATION_UTILS-------------------------------*/
void		fill_operation_list(t_push_swap *data, t_s_op e_op);
void		print_operations(t_list *head);
const char	*op_to_string(t_s_op e_op);
t_s_op		op_from(t_list *node);

/*-------------------------SWAP OPERATIONS-------------------------------*/
void		swap_a(t_push_swap *data);
void		swap_b(t_push_swap *data);
void		swap_both(t_push_swap *data);

/*------	-------------------PUSH OPERATIONS-------------------------------*/
void		push_a(t_push_swap *data);
void		push_b(t_push_swap *data);

/*------	------------------ROTATE OPERATIONS------------------------------*/
void		rotate_a(t_push_swap *data);
void		rotate_b(t_push_swap *data);
void		rotate_both(t_push_swap *data);

/*------	---------------REVERSE ROTATE OPERATIONS-------------------------*/
void		reverse_rotate_a(t_push_swap *data);
void		reverse_rotate_b(t_push_swap *data);
void		reverse_rotate_both(t_push_swap *data);

#endif
