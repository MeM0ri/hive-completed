/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:52:11 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/18 17:15:15 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"

int		main(int argc, char **argv);
void	check_operations(t_push_swap *data);
bool	test_sort(t_push_swap *data);
void	error_read_op(t_push_swap *data, char *line);
int		get_next_line_ps(int fd, char *line);
t_s_op	string_to_op(const char *str);
void	call_op(t_push_swap *data, t_s_op op);
int		ft_strcmp(const char *s1, const char *s2);

#endif
