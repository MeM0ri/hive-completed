/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:20 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/03 15:28:07 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_init_helper(char **argv, t_push_swap *data)
{
	char		**splitted_args;
	int			substr_count;

	splitted_args = ft_split(argv[1], ' ');
	substr_count = 0;
	while (splitted_args && splitted_args[substr_count])
		substr_count++;
	if (!splitted_args && substr_count < 2)
	{
		ft_putendl_fd("Error", 2);
		ft_free_array(splitted_args);
		exit(EXIT_FAILURE);
	}
	init_data(data, substr_count, splitted_args, true);
	ft_free_array(splitted_args);
}

int	main(int argc, char **argv)
{
/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\
! FOUNDED ISSUES:								!
!	- still reachable, when duplicates;			!
!	- five values wrong sorting;				!
!	- split couse mallocs when error called;	!
!	- min/max int doesn't couse errors			!
\!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

	t_push_swap	data;

	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
		split_init_helper(argv, &data);
	else
		init_data(&data, --argc, ++argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
