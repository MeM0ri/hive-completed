/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:50:54 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/27 22:45:00 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *c);
void	ft_print_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_num(int num);
void	ft_ft(int *nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_foreach(int *tab, int length, void(*f)(int));
char	*ft_strdup(char *arc);
int	ft_iterative_factorial(int nb);
int	ft_recursive_factorial(int nb);
int	ft_sqrt(int nb);
int	ft_strcmp(char *s1, char *s2);
int	ft_count_numbers_in_str(char *str);
int	ft_count_if(char **tab, int(*f)(char*));
int	*ft_range(int min, int max);

int	main(void)
{
	int	n;
	int	a;
	int	b;
	int	div;
	int	mod;
	int	square;
	int	min;
	int	max;
	int	*range;
	int	*rfe;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*ss[4];

	n = 0;
	a = -12;
	b = 34;
	s1 = "Here to compare.";
	s2 = "Here to compare.";
	min = -32;
	max = 32;
	range = ft_range(min, max);
	rfe = range;
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
	square = -10;
	printf("Square root from %i is %i\n", square, ft_sqrt(square));
	ft_putstr("Try th!$ 0ut\n");
	printf("s1: %s\ts2: %s\n", s2, s1);
	printf("Comparison result: %i\n", ft_strcmp(s2, s1));
	s3 = ft_strdup(s1);
	printf("Copy str: %s\tCopied str: %s\n", s1, s3);
	printf("Create range from %i to %i.\n", min, max);
	while (min < max)
	{
		printf("%i ", *range++);
		min++;
	}
	printf("\n");
	printf("Foreach test: \n");
	ft_foreach(rfe, 50, &ft_print_num);
	printf("\n");
	ss[0] = "Vasdwer";
	ss[1] = "oaksdl1";
	ss[2] = "1999";
	ss[3] = NULL;
	printf("Result of \"count if\": %i\n", ft_count_if(ss, ft_count_numbers_in_str));
	return (0);
}
