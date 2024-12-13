/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:36 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/13 15:49:17 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	main(void)
{
	int count_ft_printf;
	int count_printf;
	unsigned long long pointer = 0;

	printf("------------------------------ft_printf------------------------------\n");
	count_ft_printf = ft_printf("Char: %c\nString: %s\nPointer: %p\nDecimal: %d\nInteger: %i\nUnsigned decimal: %u\nhex: %x\nHEX: %X\n%% sign: %%\n", 'c', "I'm a string", &pointer, 10, 97, 10, 28, 28);
	printf("Number of chars in string with ft_printf: %i\n", count_ft_printf);
	printf("\n--------------------------------printf-------------------------------\n");
	count_printf = printf("Char: %c\nString: %s\nPointer: %p\nDecimal: %d\nInteger: %i\nUnsigned decimal: %u\nhex: %x\nHEX: %X\n%% sign: %%\n", 'c', "I'm a string", &pointer, 10, 97, 10, 28, 28);
	printf("Number of chars in string with printf: %i\n", count_printf);
	//printf("Error in input: %d\n", -10);
	return (0);
}
