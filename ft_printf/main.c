/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:04 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/13 16:18:27 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int len_sys, len_my;

	printf("_____________________________START_CHAR_TEST____________________________\n\n");

	int ch_loop = 0;
	int i = -50;

	for (; i < 200 && ch_loop == 1; i++){ // Loop Test
		printf("sys: ");
		len_sys = printf("%c", i);
		printf(" | my: ");
		fflush(stdout);
		len_my = ft_printf("%c", i);
		printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);
		printf("%d\n", i);
		printf("________________\n");
	}
	if (ch_loop == 0) // Normal Test
	{
		char a = 'a';

		printf("Normal Test\n");
		printf("sys: ");
		len_sys = printf("%c", a);
		printf(" | my: ");
		fflush(stdout);
		len_my = ft_printf("%c", a);
		printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);
	}

	printf("\n-----------------------------END_CHAR_TEST-----------------------------\n");



	printf("_____________________________START_STR_TEST____________________________\n\n");

	char *pos_str = "HELLO"; // Normal Test

	printf("Normal Test\n");
	printf("sys: ");
	len_sys = printf("%s", pos_str);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%s", pos_str);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *null_str = NULL; // Null Test

	// printf("NullTest\n");
	// printf("sys: ");
	// len_sys = printf("%s", null_str);
	// printf(" | my: ");
	// fflush(stdout);
	// len_my = ft_printf("%s", null_str);
	// printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	// printf("\n");
	// char *garb_str; // Garbage Test

	// printf("Garbage Test\n");
	// printf("sys: ");
	// len_sys = printf("%s", garb_str);
	// printf(" | my: ");
	// fflush(stdout);
	// len_my = ft_printf("%s", garb_str);
	// printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *emp_str = ""; // Empty Test

	printf("Empty Test\n");
	printf("sys: ");
	len_sys = printf("%s", emp_str);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%s", emp_str);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);


	printf("\n-----------------------------END_STR_TEST-----------------------------\n");



	printf("_____________________________START_PTR_TEST____________________________\n\n");

	void *pos_p = (void *)0x7fffffdbf2; // Normal Test

	printf("Normal Test\n");
	printf("sys: ");
	len_sys = printf("%p", pos_p);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%p", pos_p);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	void *z_p = (void *)0x0; // NULL Test

	printf("NULL Test\n");
	printf("sys: ");
	len_sys = printf("%p", z_p);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%p", z_p);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	void *opt_p = (void *)-0x484468464fa; // Optional Test

	printf("Optional Test\n");
	printf("sys: ");
	len_sys = printf("%p", opt_p);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%p", opt_p);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n-----------------------------END_PTR_TEST-----------------------------\n");



	printf("_____________________________START_INT_TEST____________________________\n\n");

	int pos_i = 456445; // Normal Test

	printf("Normal Test\n");
	printf("sys: ");
	len_sys = printf("%i", pos_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", pos_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int neg_i = -6554; // Negative Number Test

	printf("Negative Number Test\n");
	printf("sys: ");
	len_sys = printf("%i", neg_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", neg_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int zero_i = 0; // Zero Test

	printf("Zero Test\n");
	printf("sys: ");
	len_sys = printf("%i", zero_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", zero_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int hex_i = 0xff; // Hex Input Test

	printf("Hex Input Test\n");
	printf("sys: ");
	len_sys = printf("%i", hex_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", hex_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int oct_i = 0100; // Octal Input Test

	printf("Octal Input test\n");
	printf("sys: ");
	len_sys = printf("%i", oct_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", oct_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int bin_i = 0b100; // Binary Input Test

	printf("Binary Input Test\n");
	printf("sys: ");
	len_sys = printf("%i", bin_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", bin_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int min_i = -2147483648; // INT_MIN Test

	printf("INT_MIN Test\n");
	printf("sys: ");
	len_sys = printf("%i", min_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", min_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	int gar_i; // Garbage Test

	printf("Gatbage Test\n");
	printf("sys: ");
	len_sys = printf("%i", gar_i);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%i", gar_i);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n-----------------------------END_INT_TEST-----------------------------\n");

	printf("_____________________________START_UNSIGNED_TEST____________________________\n\n");

	unsigned int pos_u = 546546554; // Normal Test

	printf("Normal Test\n");
	printf("sys: ");
	len_sys = printf("%u", pos_u);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%u", pos_u);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	unsigned int neg_u = -546546554; // Crash Test

	printf("Crash Test\n");
	printf("sys: ");
	len_sys = printf("%u", neg_u);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%u", neg_u);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	unsigned int gar_u; // Garbage Test

	printf("Garbage Test\n");
	printf("sys: ");
	len_sys = printf("%u", gar_u);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%u", gar_u);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n-----------------------------END_UNSIGNED_TEST-----------------------------\n");


	printf("_____________________________START_HEX_TEST____________________________\n\n");

	int pos_hex = 45615; // Normal Test

	printf("Normal Test\n");
	printf("sys: ");
	len_sys = printf("%x", pos_hex);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%x", pos_hex);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");


	int neg_hex = -154564; // Negative Number Test

	printf("Negative Number Test\n");
	printf("sys: ");
	len_sys = printf("%x", neg_hex);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%x", neg_hex);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");

	int up_hex = -154564; // Negative UpperCase Test

	printf("Negative Number Test\n");
	printf("sys: ");
	len_sys = printf("%X", up_hex);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%X", up_hex);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");


	printf("\n-----------------------------END_HEX_TEST-----------------------------\n");

	printf("_____________________________START_PERC+SPEC_TEST____________________________\n\n");

	char *norm_per = "%%"; // Normal Test

	printf("Normal Test\n");
	printf("sys: ");
	len_sys = printf("%%", norm_per);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%%", norm_per);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *neg_per = "Good"; // One Percent Test

	printf("One Percent Test\n");
	printf("sys: ");
	len_sys = printf("%", neg_per);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%", neg_per);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);

	printf("\n");
	char *neg_spec = "Bad"; // Wrong Specifier Test

	printf("Wrong Specifier Test\n");
	printf("sys: ");
	len_sys = printf("%w", neg_spec);
	printf(" | my: ");
	fflush(stdout);
	len_my = ft_printf("%w", neg_spec);
	printf("\nsys_len: %d | my_len: %d\n", len_sys, len_my);


	printf("\n-----------------------------END_PERC+SPEC_TEST-----------------------------\n");

	return (0);
}
