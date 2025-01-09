/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:42 by alfokin           #+#    #+#             */
/*   Updated: 2025/01/09 14:17:22 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putui(unsigned int n)
{
	if (n >= 10)
		return (ft_putui(n / 10) + ft_putchar(n % 10 + '0'));
	return (ft_putchar(n + '0'));
}
