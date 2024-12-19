/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:46:04 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/19 15:23:20 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int printf_count, ft_printf_count;
	int switch_toggle;

	printf("------------------------------------char_test------------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 0:
		{
			printf("Loop ASCII Characters\n");
			for (int i = 32; i < 64 ; i++)
			{
				printf("--------------------------------------------\n\n");
				printf("ASCII character number to print: %d\n", i);
				printf("printf: ");
				printf_count = printf("%c", i);
				printf(" | ft_printf: ");
				fflush(stdout);
				ft_printf_count = ft_printf("%c", i);
				printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			}
			break;
		}
		default:
		{
			char a = 'a';
			printf("Print One Character\n");
			printf("ASCII character to print: %d\n", a);
			printf("printf: ");
			printf_count = printf("%c", a);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%c", a);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}
	printf("---------------------------------------------------------------------------------\n\n");

	printf("-------------------------------------str_test-------------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 0:
		{
			char *pos_str = "The Owls Are Not What They Seem";
			printf("Simple String Test\n");
			printf("printf: ");
			printf_count = printf("%s", pos_str);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%s", pos_str);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 1:
		{
			char *null_str = NULL;
			printf("Null String Test\n");
			printf("printf: ");
			printf_count = printf("%s", null_str);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%s", null_str);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 2:
		{
			char *emp_str = "";
			printf("Empty String Test\n");
			printf("printf: ");
			printf_count = printf("%s", emp_str);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%s", emp_str);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		default:
		{
			char *pos_str = "The Owls Are Not What They Seem";
			printf("Simple String Test\n");
			printf("printf: ");
			printf_count = printf("%s", pos_str);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%s", pos_str);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			char *null_str = NULL;
			printf("Null String Test\n");
			printf("printf: ");
			printf_count = printf("%s", null_str);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%s", null_str);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			char *emp_str = "";
			printf("Empty String Test\n");
			printf("printf: ");
			printf_count = printf("%s", emp_str);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%s", emp_str);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}

	printf("---------------------------------------------------------------------------------\n\n");

	printf("-------------------------------------ptr_test------------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 0:
		{
			void *pos_p = (void *)0x7fffffdbf2;
			printf("Normal Pointer Test\n");
			printf("printf: ");
			printf_count = printf("%p", pos_p);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%p", pos_p);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 1:
		{
			void *z_p = (void *)0x0;
			printf("NULL Pointer Test\n");
			printf("printf: ");
			printf_count = printf("%p", z_p);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%p", z_p);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 2:
		{
			void *opt_p = (void *)-0x484468464fa;
			printf("Below Zero Pointer Test\n");
			printf("printf: ");
			printf_count = printf("%p", opt_p);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%p", opt_p);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		default:
		{
			void *pos_p = (void *)0x7fffffdbf2;
			printf("Normal Pointer Test\n");
			printf("printf: ");
			printf_count = printf("%p", pos_p);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%p", pos_p);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			void *z_p = (void *)0x0;
			printf("NULL Pointer Test\n");
			printf("printf: ");
			printf_count = printf("%p", z_p);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%p", z_p);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			void *opt_p = (void *)-0x484468464fa;
			printf("Below Zero Pointer Test\n");
			printf("printf: ");
			printf_count = printf("%p", opt_p);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%p", opt_p);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}

	printf("---------------------------------------------------------------------------------\n\n");

	printf("-------------------------------------num_test------------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 0:
		{
			int pos_i = 456445;
			printf("Normal Test\n");
			printf("printf: ");
			printf_count = printf("%i", pos_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", pos_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 1:
		{
			int neg_i = -6554; // Negative Number Test
			printf("Negative Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", neg_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", neg_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 2:
		{
			int zero_i = 0;
			printf("Zero Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", zero_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", zero_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 3:
		{
			int hex_i = 0xff;
			printf("Hex Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", hex_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", hex_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 4:
		{
			int oct_i = 0100;
			printf("Octal Number test\n");
			printf("printf: ");
			printf_count = printf("%i", oct_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", oct_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 5:
		{
			int bin_i = 0b100;
			printf("Binary Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", bin_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", bin_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 6:
		{
			int min_i = -2147483648;
			printf("INT_MIN Test\n");
			printf("printf: ");
			printf_count = printf("%i", min_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", min_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 7:
		{
			int gar_i;
			printf("Garbage Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", gar_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", gar_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		default:
		{
			int pos_i = 456445;
			printf("Normal Test\n");
			printf("printf: ");
			printf_count = printf("%i", pos_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", pos_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int neg_i = -6554; // Negative Number Test
			printf("Negative Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", neg_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", neg_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int zero_i = 0;
			printf("Zero Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", zero_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", zero_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int hex_i = 0xff;
			printf("Hex Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", hex_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", hex_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int oct_i = 0100;
			printf("Octal Number test\n");
			printf("printf: ");
			printf_count = printf("%i", oct_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", oct_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int bin_i = 0b100;
			printf("Binary Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", bin_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", bin_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int min_i = -2147483648;
			printf("INT_MIN Test\n");
			printf("printf: ");
			printf_count = printf("%i", min_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", min_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int gar_i;
			printf("Garbage Number Test\n");
			printf("printf: ");
			printf_count = printf("%i", gar_i);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%i", gar_i);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}

	printf("---------------------------------------------------------------------------------\n\n");

	printf("-------------------------------unsigned_num_test---------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 1:
		{
			unsigned int pos_u = 546546554;
			printf("Unsigned Integer Test\n");
			printf("printf: ");
			printf_count = printf("%u", pos_u);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%u", pos_u);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 2:
		{
			unsigned int neg_u = -546546554;
			printf("Negative Unsigned Integer Test\n");
			printf("printf: ");
			printf_count = printf("%u", neg_u);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%u", neg_u);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 3:
		{
			unsigned int gar_u;
			printf("Unsigned Integer Garbage Test\n");
			printf("printf: ");
			printf_count = printf("%u", gar_u);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%u", gar_u);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		default:
		{
			unsigned int pos_u = 546546554;
			printf("Unsigned Integer Test\n");
			printf("printf: ");
			printf_count = printf("%u", pos_u);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%u", pos_u);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			unsigned int neg_u = -546546554;
			printf("Negative Unsigned Integer Test\n");
			printf("printf: ");
			printf_count = printf("%u", neg_u);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%u", neg_u);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			unsigned int gar_u;
			printf("Unsigned Integer Garbage Test\n");
			printf("printf: ");
			printf_count = printf("%u", gar_u);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%u", gar_u);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}

	printf("---------------------------------------------------------------------------------\n\n");

	printf("-------------------------------------hex_test------------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 1:
		{
			int pos_low_hex = 45615;
			printf("Lowercase Hex Test\n");
			printf("printf: ");
			printf_count = printf("%x", pos_low_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%x", pos_low_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 2:
		{
			int pos_up_hex = 45615;
			printf("Uppercase Hex Test\n");
			printf("printf: ");
			printf_count = printf("%X", pos_up_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%X", pos_up_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 3:
		{
			long long neg_low_hex = -15456412341;
			printf("Negative Lower Hex Test\n");
			printf("printf: ");
			printf_count = printf("%x", neg_low_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%x", neg_low_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 4:
		{
			long long neg_up_hex = -15456412341;
			printf("Negative Upper Hex Test\n");
			printf("printf: ");
			printf_count = printf("%X", neg_up_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%X", neg_up_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		default:
		{
			int pos_low_hex = 45615;
			printf("Lowercase Hex Test\n");
			printf("printf: ");
			printf_count = printf("%x", pos_low_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%x", pos_low_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			int pos_up_hex = 45615;
			printf("Uppercase Hex Test\n");
			printf("printf: ");
			printf_count = printf("%X", pos_up_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%X", pos_up_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			long long neg_low_hex = -15456412341;
			printf("Negative Lower Hex Test\n");
			printf("printf: ");
			printf_count = printf("%x", neg_low_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%x", neg_low_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			long long neg_up_hex = -15456412341; // Negative UpperCase Test
			printf("Negative Upper Hex Test\n");
			printf("printf: ");
			printf_count = printf("%X", neg_up_hex);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%X", neg_up_hex);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}

	printf("---------------------------------------------------------------------------------\n\n");

	printf("------------------------------------misc_test------------------------------------\n\n");
	switch_toggle = 10;

	switch (switch_toggle)
	{
		case 1:
		{
			char *norm_per = "%%";
			printf("Percentage Sign Test\n");
			printf("printf: ");
			printf_count = printf("%%", norm_per);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%%", norm_per);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 2:
		{
			char *neg_per = "Good";
			printf("Only Percentage Sign Test\n");
			printf("printf: ");
			printf_count = printf("% ", neg_per);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("% ", neg_per);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		case 3:
		{
			char *neg_spec = "Bad";
			printf("Wrong Specifier Test\n");
			printf("printf: ");
			printf_count = printf("%w", neg_spec);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%w", neg_spec);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
		default:
		{
			char *norm_per = "%%";
			printf("Percentage Sign Test\n");
			printf("printf: ");
			printf_count = printf("%%", norm_per);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%%", norm_per);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			char *neg_per = "Good";
			printf("Only Percentage Sign Test\n");
			printf("printf: ");
			printf_count = printf("% ", neg_per);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("% ", neg_per);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);

			printf("--------------------------------------------\n\n");
			char *neg_spec = "Bad";
			printf("Wrong Specifier Test\n");
			printf("printf: ");
			printf_count = printf("%w", neg_spec);
			printf(" | ft_printf: ");
			fflush(stdout);
			ft_printf_count = ft_printf("%w", neg_spec);
			printf("\nprintf counter: %d | ft_printf counter: %d\n\n", printf_count, ft_printf_count);
			break;
		}
	}

	printf("---------------------------------------------------------------------------------\n");

	return (0);
}
