/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:18 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/01 17:04:56 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*s;
	char	*dest1;
	char	*dest2;
	char	*dest3;
	char	*dest4;
	char	*dest5;
	int		c;
	int		result;
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

	printf("\n--------------------/ft_strlcpy\\------------------------\n");
	i = ft_strlcpy(dest2, "   0123456789012345678", n);
	printf("Null terminate index of dest is: %lli.\nDest is: %s\n", n, dest2);

	printf("\n--------------------/ft_strlcat\\------------------------\n");
	dest3 = (char *)ft_calloc(20, sizeof(char));
	i = ft_strlcpy(dest3, "portrotpsss", 10);
	printf("Original string: %s\nString to cancatanate: %s\n", dest3, dest2);
	ft_strlcat(dest3, dest2, 20);
	printf("Cancatanated string: %s\n", dest3);

	printf("\n--------------------/ft_toupper\\------------------------\n");
	c = 102;
	printf("Change %c to upper: %c\n", (char)c, (char)ft_toupper(c));

	printf("\n--------------------/ft_tolower\\------------------------\n");
	c = 70;
	printf("Change %c to lower: %c\n", (char)c, (char)ft_tolower(c));

	printf("\n---------------------/ft_strchr\\------------------------\n");
	c = 112;
	dest4 = ft_strchr(dest3, c);
	printf("Inside \"%s\" address of the first \"%c\" is: %s\n", dest3, c, dest4);

	printf("\n--------------------/ft_strrchr\\------------------------\n");
	c = 120;
	dest4 = ft_strrchr(dest3, c);
	printf("Inside \"%s\" address of the last \"%c\" is: %s\n", dest3, c, dest4);

	printf("\n--------------------/ft_strncmp\\------------------------\n");
	n = 15;
	result = ft_strncmp(dest2, dest2, n);
	printf("Compare first %lli characters of \"%s\" with \"%s\": %i\n", n, dest2, dest2, result);

	printf("\n---------------------/ft_memchr\\------------------------\n");
	c = 116;
	n = 15;
	dest4 = ft_memchr(dest3, c, n);
	printf("Address of \"%c\" in %lli first characters of \"%s\": %x\n", (char)c, n, dest3, dest4);

	printf("\n---------------------/ft_memcmp\\------------------------\n");
	n = 10;
	result = ft_memcmp(dest1, s, n);
	printf("Compare s1 and s2 memory locations in first %lli: %i\n", n, result);

	printf("\n--------------------/ft_strnstr\\------------------------\n");
	dest2 = "This is Haloween!";
	dest3 = "Haloween";
	printf("Is there string \"%s\" inside \"%s\": %s\n", dest2, dest3, ft_strnstr(dest2, dest3, ft_strlen(dest2)));

	printf("\n-----------------------/ft_atoi\\------------------------\n");
	dest2 = "    -233455sdfx";
	printf("Parse string \"%s\" into int: %i\n", dest2, ft_atoi(dest2));

	printf("\n---------------------/ft_calloc\\------------------------\n");
	n = 10;
	dest5 = (char *)ft_calloc(n, sizeof(char));
	printf("Allocate %lli memory cells for a string: ", n);
	i = 0;
	while (i < n - 1)
		printf("| %c ", dest5[i++]);
	printf("| %c |\n", dest5[i]);
	free(dest5);

	printf("\n---------------------/ft_strdup\\------------------------\n");
	dest5 = ft_strdup(dest3);
	printf("Duplicate string \"%s\": %s", dest3, dest5);

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
	//free(dest2);
	//free(dest3);
	return (0);
}
