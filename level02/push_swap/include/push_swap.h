/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:12:33 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/17 17:29:07 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "stack.h"

int	main(int argc, char **argv);

/*-------------------------------SORT------------------------------------*/
void	sort(t_push_swap *data);
void	sort_three_a(t_push_swap *data);

/*----------------------------SORT_UTILS---------------------------------*/
bool	is_sorted(t_stack *stack_data);

#endif
