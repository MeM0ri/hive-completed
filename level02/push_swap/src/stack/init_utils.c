/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:10:54 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/15 14:31:20 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* Calling for initializing stacks 'a' and 'b'.			*/
/* Call for filling stack 'a' with values from argv.	*/
/* Declaring operation list and writing mode.			*/
void	init_data(t_push_swap *data, int argc, char **argv, bool write_mode)
{
	argc--;
	init_stack(data, &data->stack_a, argc);
	init_stack(data, &data->stack_b, argc);
	fill_stack(data, &data->stack_a, argc, ++argv);
	data->op_list = NULL;
	data->write_mode = write_mode;
}

/* Initializing stack. Allocating memory for given stack size.				*/
/* Filling stack and their top and bottom properties with initial zeroes.	*/
void	init_stack(t_push_swap *data, t_stack *stack_data, int stack_size)
{
	stack_data->stack = malloc(stack_size + sizeof(int));
	if (!stack_data->stack)
		error(data);
	stack_data->top = 0;
	stack_data->bottom = 0;
	stack_data->size = stack_size;
	ft_memset(stack_data->stack, 0, sizeof(int) * stack_size);
}

/* Initial filling stack 'a' with values from argv, converted to int.	*/
/* Also declaring top and bottom values of stack structure.				*/
void	fill_stack(t_push_swap *data, t_stack *stack_data, int stack_size, char **values)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (!is_valid_value(*values))
			error(data);
		stack_data->stack[i] = ft_atoi(*values);
		i++;
		values++;
	}
	is_duplicates(data, stack_data, stack_size);
	stack_data->top = stack_data->stack[0];
	stack_data->bottom = stack_data->stack[stack_size - 1];
}
