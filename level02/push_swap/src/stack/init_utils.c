/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:10:54 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/11 20:49:50 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/* Calling for initializing stacks 'a' and 'b'.			*/
/* Call for filling stack 'a' with values from argv.	*/
/* Declaring operation list and writing mode.			*/
bool	init_data(t_push_swap *data, int argc, char **argv, bool write_mode)
{
	data->stack_a.stack = NULL;
	data->stack_b.stack = NULL;
	data->op_list = NULL;
	if (!init_stack(&data->stack_a, argc) || !init_stack(&data->stack_b, argc))
		return (false);
	if (fill_stack(data, &data->stack_a, argc, argv))
		return (false);
	data->write_mode = write_mode;
	return (true);
}

/* Initializing stack. Allocating memory for given stack size.				*/
/* Filling stack and their top and bottom indexes with initial zeroes.		*/
bool	init_stack(t_stack *stack_data, int stack_size)
{
	stack_data->stack = malloc(stack_size * sizeof(int));
	if (!stack_data->stack)
		return (false);
	stack_data->top = 0;
	stack_data->bottom = 0;
	stack_data->size = stack_size;
	ft_memset(stack_data->stack, 0, sizeof(int) * stack_size);
	return (true);
}

/* Set ranks instead of random numbers from atguments */
void	random_to_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	count_smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		count_smaller = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				count_smaller++;
		rank[i] = count_smaller;
		i++;
	}
}

/* Initial filling stack 'a' with values from argv, converted to int.	*/
/* Also declaring bottom index of stack structure.						*/
bool	fill_stack(t_push_swap *data, t_stack *stack_data, int stack_size,
			char **values)
{
	int		*numbers;
	int		i;
	bool	res;

	numbers = malloc(sizeof(int) * stack_size);
	if (!numbers)
		error(data);
	i = -1;
	while (values[++i])
	{
		if (!is_valid_value(values[i]))
		{
			free(numbers);
			return (true);
		}
		numbers[i] = ft_atoi(values[i]);
	}
	res = is_duplicates(numbers, stack_size);
	if (!res)
	{
		random_to_rank(numbers, stack_data->stack, stack_size);
		stack_data->bottom = stack_size - 1;
	}
	free(numbers);
	return (res);
}
