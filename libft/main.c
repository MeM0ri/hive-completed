/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:18 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/31 17:29:47 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*s;
	char	*dest1;
	char	*dest2;
	int		c;
	size_t	n;
	size_t	i;

	printf("\n--------------------/ft_isalpha\\------------------------\n");
	printf("Is char an alpha: %i\n", ft_isalpha('1'));

	printf("\n--------------------/ft_isdigit\\------------------------\n");
	printf("Is char a digit: %i\n", ft_isdigit('a'));

	printf("\n--------------------/ft_isalnum\\------------------------\n");
	printf("Is char an alpha or a digit: %i\n", ft_isalnum(' '));

	printf("\n--------------------/ft_isascii\\------------------------\n");
	printf("Is char an ascii: %i\n", ft_isascii('1'));

	printf("\n--------------------/ft_isprint\\------------------------\n");
	printf("Is char printable: %i\n", ft_isprint('1'));

	printf("\n---------------------/ft_strlen\\------------------------\n");
	printf("String length: %lli\n", ft_strlen("Here is 10"));

	printf("\n---------------------/ft_memset\\------------------------\n");
	n = 10;
	c = 65;
	s = malloc(n);
	ft_memset(s, c, n);
	printf("Setted memory is: %s\n", s);

	printf("\n----------------------/ft_bzero\\------------------------\n");
	n = 2;
	i = 0;
	ft_bzero(s, n);
	printf("Emptied %lli bites of s: ", n);
	while (i < 9)
		printf("| %c ", s[i++]);
	printf("| %c |\n", s[i]);

	printf("\n---------------------/ft_memcpy\\------------------------\n");
	n = 10;
	dest1 = malloc(n);
	dest1 = ft_memcpy(dest1, s, n);
	printf("Copy src: ");
	i = 0;
	while (i < n - 1)
		printf("| %c ", s[i++]);
	printf("| %c |\n", s[i]);
	printf("To dest: ");
	i = 0;
	while (i < n - 1)
		printf("| %c ", dest1[i++]);
	printf("| %c |\n", dest1[i]);

	printf("\n--------------------/ft_memmove\\------------------------\n");
	n = 16;
	dest2 = malloc(n);
	dest2 = ft_memmove(dest2, s, n);
	printf("Copy src: ");
	i = 0;
	while (i < n - 1)
		printf("| %c ", s[i++]);
	printf("| %c |\n", s[i]);
	printf("To dest: ");
	i = 0;
	while (i < n - 1)
		printf("| %c ", dest2[i++]);
	printf("| %c |\n", dest2[i]);

	printf("\n-------------------/ft_mstrlcpy\\------------------------\n");
	printf("\n--------------------/ft_strlcat\\------------------------\n");
	printf("\n--------------------/ft_toupper\\------------------------\n");
	printf("\n--------------------/ft_tolower\\------------------------\n");
	printf("\n---------------------/ft_strchr\\------------------------\n");
	printf("\n--------------------/ft_strrchr\\------------------------\n");
	printf("\n--------------------/ft_strncmp\\------------------------\n");
	printf("\n---------------------/ft_memchr\\------------------------\n");
	printf("\n---------------------/ft_memcmp\\------------------------\n");
	printf("\n--------------------/ft_strnstr\\------------------------\n");
	printf("\n-----------------------/ft_atoi\\------------------------\n");
	printf("\n---------------------/ft_calloc\\------------------------\n");
	printf("\n---------------------/ft_strdup\\------------------------\n");
	printf("\n---------------------/ft_substr\\------------------------\n");
	printf("\n--------------------/ft_strjoin\\------------------------\n");
	printf("\n--------------------/ft_strtrim\\------------------------\n");
	printf("\n----------------------/ft_split\\------------------------\n");
	printf("\n-----------------------/ft_itoa\\------------------------\n");
	printf("\n--------------------/ft_strmapi\\------------------------\n");
	printf("\n-------------------/ft_striteri\\------------------------\n");
	printf("\n-----------------/ft_putchar_fd\\------------------------\n");
	printf("\n------------------/ft_putstr_fd\\------------------------\n");
	printf("\n-----------------/ft_putendl_fd\\------------------------\n");
	printf("\n------------------/ft_putnbr_fd\\------------------------\n");

	free(s);
	free(dest1);
	return (0);
}
