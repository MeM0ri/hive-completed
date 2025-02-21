/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:54:04 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/21 16:24:53 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error_read_op(t_push_swap *data, char *line)
{
	if (line)
		free(line);
	error(data);
}

int	ps_get_next_line(int fd, char *line)
{
	int		i;
	int		read_status;
	char	char_buffer;

	i = 0;
	char_buffer = ' ';
	while (char_buffer != '\n')
	{
		read_status = read(fd, &char_buffer, 1);
		if (read_status == -1)
			return (EXIT_FAILURE);
		if (read_status == 0)
			break ;
		line[i++] = char_buffer;
		if (i > 4)
			return (EXIT_FAILURE);
	}
	if ((i > 0 && line[i - 1] != '\n') || line[0] == '\n')
		return (EXIT_FAILURE);
	if (read_status == 0)
		line[0] = '\0';
	else
		line[i - 1] = '\0';
	return (EXIT_SUCCESS);
}

t_s_op	string_to_op(const char *str)
{
	if (!ft_strcmp(str, "pa"))
		return (pa);
	else if (!ft_strcmp(str, "pb"))
		return (pb);
	else if (!ft_strcmp(str, "rra"))
		return (rra);
	else if (!ft_strcmp(str, "rrb"))
		return (rrb);
	else if (!ft_strcmp(str, "rrr"))
		return (rrr);
	else if (!ft_strcmp(str, "ra"))
		return (ra);
	else if (!ft_strcmp(str, "rb"))
		return (rb);
	else if (!ft_strcmp(str, "rr"))
		return (rr);
	else if (!ft_strcmp(str, "sa"))
		return (sa);
	else if (!ft_strcmp(str, "sb"))
		return (sb);
	else if (!ft_strcmp(str, "ss"))
		return (ss);
	else
		return (null_op);
}

void	call_op(t_push_swap *data, t_s_op op)
{
	if (op == pa)
		push_a(data);
	else if (op == pb)
		push_b(data);
	else if (op == rra)
		reverse_rotate_a(data);
	else if (op == rrb)
		reverse_rotate_b(data);
	else if (op == rrr)
		reverse_rotate_both(data);
	else if (op == ra)
		rotate_a(data);
	else if (op == rb)
		rotate_b(data);
	else if (op == rr)
		rotate_both(data);
	else if (op == sa)
		swap_a(data);
	else if (op == sb)
		swap_b(data);
	else if (op == ss)
		swap_both(data);
	else
		error(data);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
