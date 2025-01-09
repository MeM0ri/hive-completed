/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:12:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/09 16:22:03 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_list
{
	int					data;
	struct s_stack_list	*next;
	struct s_stack_list	*prev;
}	t_stack_list;

/*------------------------ft_printf functions-----------------------------*/
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putptr(void *ptr);
int		ft_putui(unsigned int n);
int		ft_putnbr(int n, int count);
int		ft_puthex(unsigned long long n, int count, const char type);
/*--------------------------libft functions-------------------------------*/
size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(char	const *s, char c);
/*------------------------push_swap functions-----------------------------*/
t_stack_list *create_node(int data);
void	insert_node(t_stack_list **node, int data);

#endif
