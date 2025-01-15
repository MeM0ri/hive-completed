/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:01 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/15 15:51:26 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

/*-------------------------STACK STRUCTURE------------------------------*/
typedef struct s_stack
{
	int	*stack;
	int	size;
	int	top;
	int	bottom;
}	t_stack;

typedef struct	s_push_swap
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_list	*op_list;
	bool	write_mode;
}	t_push_swap;

enum	e_stack_operations
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
};


/*----------------------------INIT UTILS---------------------------------*/
void	init_data(t_push_swap *data, int argc, char **argv, bool write_mode);
void	init_stack(t_push_swap *data, t_stack *stack_data, int stack_size);
void	fill_stack(t_push_swap *data, t_stack *stack_data, int stack_size, char **values);

/*--------------------------ERROR_HANDLER-------------------------------*/
void	error(t_push_swap *data);

/*-------------------------CHECK_FUNCTIONS------------------------------*/
bool	is_valid_value(char *value);
void	is_duplicates(t_push_swap *data, t_stack *stack_data, int stack_size);

/*----------------------------FREE_DATA---------------------------------*/
void	free_data(t_push_swap *data);

/*-------------------------SWAP OPERATIONS------------------------------*/
void	swap(t_stack *stack_data);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);

/*-------------------------PUSH OPERATIONS------------------------------*/

/*------------------------ROTATE OPERATIONS-----------------------------*/

/*---------------------REVERSE ROTATE OPERATIONS------------------------*/


#endif
