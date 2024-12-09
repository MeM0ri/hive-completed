/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:36 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/09 16:57:53 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>

int	main(void)
{
	int count_ft_printf;
	int count_printf;

	printf("------------------------------ft_printf------------------------------\n");
	count_ft_printf = ft_printf("Char: %c\nString: %s\nDecimal: %d\nInteger: %i\nhex: %x\nHEX: %X\n", 'c', "I'm a string", 10, 97, 28, 28);
	printf("Number of chars in string with ft_printf: %i\n", count_ft_printf);
	printf("\n--------------------------------printf-------------------------------\n");
	count_printf = printf("Char: %c\nString: %s\nDecimal: %d\nInteger: %i\nhex: %x\nHEX: %X\n", 'c', "I'm a string", 10, 97, 28, 28);
	printf("Number of chars in string with printf: %i\n", count_printf);
	//printf("Error in input: %d\n", -10);
	return (0);
}
