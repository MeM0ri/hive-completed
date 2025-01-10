/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:48:01 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/10 15:17:20 by alfokin          ###   ########.fr       */
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
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/*------------------------STACK DECLARATION-----------------------------*/
t_stack	*create_node(int data);
void	insert_node(t_stack **node, int data);

/*-------------------------SWAP OPERATIONS------------------------------*/
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

#endif
