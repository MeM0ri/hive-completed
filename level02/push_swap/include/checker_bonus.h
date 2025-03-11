/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:52:11 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/11 15:00:44 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

/*-------------------------------MAIN------------------------------------*/
int		main(int argc, char **argv);
void	split_init_helper(char **argv, t_push_swap *data);
void	read_operations(t_push_swap *data);
bool	test_sort(t_push_swap *data);

/*-------------------------------UTILS-----------------------------------*/
void	error_read_op(t_push_swap *data, char *line);
void	call_op(t_push_swap *data, t_s_op op);
int		ps_get_next_line(int fd, char *line);
int		ft_strcmp(const char *s1, const char *s2);
t_s_op	string_to_op(const char *str);

#endif
