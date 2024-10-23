/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:50:54 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/23 23:48:28 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_num(int num);
void	ft_ft(int *nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);

int	main(void)
{
	int	n;
	int	a;
	int	b;
	int	div;
	int	mod;

	n = 0;
	a = -12;
	b = 34;
	ft_print_alphabet();
	ft_putchar('\n');
	ft_print_numbers();
	ft_putchar('\n');
	ft_is_negative(-10);
	ft_putchar('\n');
	ft_ft(&n);
	ft_print_num(n);
	ft_putchar('\n');
	printf("a: %i\tb: %i\n", a, b);
	ft_swap(&a, &b);
	printf("a: %i\tb: %i\n", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("div: %i\tmod: %i\n", div, mod);
	printf("Iterative factorial: %i\n", ft_iterative_factorial(12));
	printf("Recursive factorial: %i\n", ft_recursive_factorial(12));
	return (0);
}
