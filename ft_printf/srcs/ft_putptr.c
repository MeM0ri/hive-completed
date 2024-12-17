/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:36:15 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/17 14:48:48 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putptr(void *ptr)
{
	if (ptr == 0)
	{
		//write(1, "(nil)", 5);
		printf("(nil)");
		return (5);
	}
	//write(1, "0x", 2);
	printf("0x");
	return (ft_puthex((unsigned long long)ptr, 2, 'x'));
}
