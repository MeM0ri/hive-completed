/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:10:54 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/05 17:58:44 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* Initialize stack 'real_zero' properties with default 'false' */
void	set_default_bools(t_stack *stack_data, int stack_size)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		stack_data->real_zero[i] = false;
		i++;
	}
}

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
/* Filling stack and their top and bottom indexes with initial zeroes.		*/
void	init_stack(t_push_swap *data, t_stack *stack_data, int stack_size)
{
	stack_data->stack = malloc(stack_size + sizeof(int));
	if (!stack_data->stack)
		error(data);
	stack_data->real_zero = malloc(stack_size + sizeof(bool));
	if (!stack_data->real_zero)
		error(data);
	set_default_bools(stack_data, stack_size);
	stack_data->top = 0;
	stack_data->bottom = 0;
	stack_data->size = stack_size;
	ft_memset(stack_data->stack, 0, sizeof(int) * stack_size);
}

/* Initial filling stack 'a' with values from argv, converted to int.	*/
/* Also declaring bottom index of stack structure.						*/
void	fill_stack(t_push_swap *data, t_stack *stack_data, int stack_size,
char **values)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		if (!is_valid_value(*values))
			error(data);
		stack_data->stack[i] = ft_atoi(*values);
		if (stack_data->stack[i] == 0)
			stack_data->real_zero[i] = true;
		i++;
		values++;
	}
	is_duplicates(data, stack_data, stack_size);
	stack_data->bottom = stack_size - 1;
}
