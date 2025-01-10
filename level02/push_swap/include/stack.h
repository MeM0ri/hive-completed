/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:01 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/10 16:17:44 by alfokin          ###   ########.fr       */
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


/*----------------------------DATA UTILS---------------------------------*/
void	init_data(t_push_swap *data, int argc, char **argv, bool write_mode);

/*-------------------------SWAP OPERATIONS------------------------------*/
// void	swap(t_stack **stack);
// void	sa(t_stack **a);
// void	sb(t_stack **b);
// void	ss(t_stack **a, t_stack **b);

#endif
