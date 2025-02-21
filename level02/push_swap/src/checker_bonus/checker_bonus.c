/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:09 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/21 16:25:27 by alfokin          ###   ########.fr       */
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
	read_operations(&data);
	if (test_sort(&data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&data);
	exit(EXIT_SUCCESS);
}

void	read_operations(t_push_swap *data)
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
		gnl_status = ps_get_next_line(0, line);
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
	int		i;
	int		lst_size;

	reader = data->op_list;
	lst_size = ft_lstsize(reader);
	i = 0;
	while (i < lst_size)
	{
		call_op(data, (t_s_op)(uintptr_t)reader->content);
		reader = reader->next;
		i++;
	}
	if (data->stack_a.size == current_stack_size(&data->stack_a)
			&& is_sorted(&data->stack_a))
		return (true);
	return (false);
}
