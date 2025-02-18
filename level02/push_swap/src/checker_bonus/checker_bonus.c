/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:09 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/18 17:18:32 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_push_swap	data;
	char		**splitted_args;
	int			substr_count;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		splitted_args = ft_split(argv[1], ' ');
		substr_count = 0;
		while (splitted_args[substr_count])
			substr_count++;
		if (!splitted_args)
			exit(EXIT_FAILURE);
		init_data(&data, substr_count, splitted_args, true);
	}
	else
		init_data(&data, --argc, ++argv, true);
	free_data(&data);
	exit(EXIT_SUCCESS);
}

void	check_operations(t_push_swap *data)
{
	t_list	*op_check_list;
	int		gnl_status;
	char	*line;
	int		line_status;

	gnl_status = 0;
	line_status = 1;
	line = malloc(sizeof(char) * 5);
	if (!line)
		error_read_op(data, line);
	while (line_status)
	{
		gnl_status = get_next_line_ps(0, line);
		if (gnl_status == EXIT_FAILURE)
			error_read_op(data, line);
		line_status = ft_strlen(line);
		if (line_status == 0)
			break ;
		op_check_list = ft_lstnew((void *)(uintptr_t)string_to_op(line));
		if (!op_check_list)
			error_read_op(data, line);
		ft_lstadd_back(&data->op_list, op_check_list);
	}
	free(line);
}

bool	test_sort(t_push_swap *data)
{
	t_list	*reader;

	reader = data->op_list;
	while (reader)
	{
		call_op(data, (t_s_op)(uintptr_t)reader->content);
		reader = reader->next;
	}
	if (data->stack_a.size == current_stack_size(&data->stack_a)
			&& is_sorted(&data->stack_a))
		return (true);
	return (false);
}
