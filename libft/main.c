/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:52:18 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/08 13:23:40 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "libft.h"

#define BUFFER_SIZE 1024

size_t	ft_count_str(char const **s)
{
	size_t	num_s;

	num_s = 0;
	while (s[num_s])
		num_s++;
	return (num_s);
}

char	ft_check_strmapi(unsigned int index, char c)
{
	(void)index;
	return ft_toupper(c);
}

void	ft_check_striteri(unsigned int index, char *c)
{
	(void)index;
	*c = ft_toupper(*c);
	return ;
}

void	ft_read_from_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		perror("Error seeking file");
		close(fd);
	}

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(STDOUT_FILENO, buffer, bytes_read);
	if (bytes_read == -1)
		perror("Error reading file");
}

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// void	ft_print_result2(int n)
// {
// 	char c;

// 	if (n >= 10)
// 		ft_print_result2(n / 10);
// 	c = n % 10 + '0';
// 	write (1, &c, 1);
// }

// void	ft_print_result_add(t_list *elem)
// {
// 	int		len;

// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, elem->content, len);
// 	write(1, "\n", 1);
// }

// t_list	*ft_lstnewone(void *content)
// {
// 	t_list	*elem;

// 	elem = (t_list *)malloc(sizeof(t_list));
// 	if (!elem)
// 		return (NULL);
// 	if (!content)
// 		elem->content = NULL;
// 	else
// 		elem->content = content;
// 	elem->next = NULL;
// 	return (elem);
// }

// static int	nb_free_done;

// void	ft_del(void *content)
// {
// 	free(content);
// 	nb_free_done++;
// }

// void	ft_print_result_del(t_list *elem)
// {
// 	write(1, elem->content, strlen(elem->content));
// }

int	main(void)
{
	char	*s;
	char	*dest1;
	char	*dest2;
	char	*dest3;
	char	*dest4;
	char	*dest5;
	char	*dest6;
	char	*substr;
	char	*joined_str;
	char	*trimmed_str;
	char	**splitted_string;
	int		c;
	int		result;
	int		fd;
	size_t	n;
	size_t	i;
	/*------------------Bonus Part Var's--------------------------*/
	// t_list		*begin;
	// t_list		*elem;
	// t_list		*elem2;
	// t_list		*elem3;
	// t_list		*elem4;
	// char		*str = strdup("lorem");
	// char		*str2 = strdup("ipsum");
	// char		*str3 = strdup("dolor");
	// char		*str4 = strdup("sit");

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
	printf("String length: %lu\n", ft_strlen("Here is 10"));

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
	printf("Emptied %lu bites of s: ", n);
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
	printf("Null terminate index of dest is: %lu.\nDest is: %s\n", n, dest2);

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
	printf("Compare first %lu characters of \"%s\" with \"%s\": %i\n", n, dest2, dest2, result);

	printf("\n---------------------/ft_memchr\\------------------------\n");
	c = 116;
	n = 15;
	dest4 = ft_memchr(dest3, c, n);
	printf("Address of \"%c\" in %lu first characters of \"%s\": %s\n", (char)c, n, dest3, dest4);

	printf("\n---------------------/ft_memcmp\\------------------------\n");
	n = 10;
	result = ft_memcmp(dest1, s, n);
	printf("Compare s1 and s2 memory locations in first %lu: %i\n", n, result);

	printf("\n--------------------/ft_strnstr\\------------------------\n");
	dest2 = "This is Haloween!";
	dest3 = "Haloween";
	printf("Is there string \"%s\" inside \"%s\": %s\n", dest2, dest3, ft_strnstr(dest2, dest3, ft_strlen(dest2)));

	printf("\n-----------------------/ft_atoi\\------------------------\n");
	dest2 = "    -2147483648sdfx";
	printf("Parse string \"%s\" into int: %i\n", dest2, ft_atoi(dest2));

	printf("\n---------------------/ft_calloc\\------------------------\n");
	n = 123123123123123;
	dest5 = (char *)ft_calloc(n, sizeof(char));
	printf("Allocate %lu memory cells for a string: ", n);
	i = 0;
	while (i < n - 1)
		printf("| %c ", dest5[i++]);
	printf("| %c |\n", dest5[i]);
	free(dest5);

	printf("\n---------------------/ft_strdup\\------------------------\n");
	dest5 = ft_strdup(dest3);
	printf("Duplicate string \"%s\": %s", dest3, dest5);

	printf("\n---------------------/ft_substr\\------------------------\n");
	c = 10;
	n = 10;
	dest3 = "Kinuli prjamo v jamu kamen'";
	substr = ft_substr(dest3, c, n);
	printf("Substr from \"%s\" with start point at %i and length %lu: %s\n", dest3, c, n, substr);

	printf("\n--------------------/ft_strjoin\\------------------------\n");
	dest2 = "Gorod usnul on slowno ne jhiwoj ";
	dest3 = "Moja ten' - jedinstwennyj drug moj";
	joined_str = ft_strjoin(dest2, dest3);
	printf("Join string \"%s\" and string \"%s\": %s\n", dest2, dest3, joined_str);

	printf("\n--------------------/ft_strtrim\\------------------------\n");
	dest2 = "";
	dest3 = "";
	trimmed_str = ft_strtrim(dest2, dest3);
	printf("Trim string \"%s\" with set \"%s\": %s\n", dest2, dest3, trimmed_str);

	printf("\n----------------------/ft_split\\------------------------\n");
	c = 120;
	dest2 = "x1x1x1x1x1x1x1xhello!";
	splitted_string = ft_split(dest2, (char)c);
	printf("Split string \"%s\" by character \"%c\": \n", dest2, (char)c);
	n = ft_count_str((char const **)splitted_string) - 1;
	while (n != 0)
	{
		printf("%s\n", *splitted_string);
		n--;
		splitted_string++;
	}
	printf("%s\n", *splitted_string);

	printf("\n-----------------------/ft_itoa\\------------------------\n");
	result = -234556;
	dest3 = ft_itoa(result);
	printf("Convert %i integer to string: %s\n", result, dest3);

	printf("\n--------------------/ft_strmapi\\------------------------\n");
	dest3 = ft_strmapi(dest2, &ft_check_strmapi);
	printf("String \"%s\" to function ft_bzero: %s\n", dest2, dest3);

	printf("\n-------------------/ft_striteri\\------------------------\n");
	dest6 = malloc(ft_strlen("pls, letmein") + 1);
	ft_strlcpy(dest6, "pls, letmein", ft_strlen("pls, letmein") + 1);
	i = 0;
	printf("Iteratively use function on existing string \"%s\": ", dest6);
	ft_striteri(dest6, &ft_check_striteri);
	printf("%s\n", dest6);

	printf("\n-----------------/ft_putchar_fd\\------------------------\n");
	fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	ft_putchar_fd('U', fd);
	ft_putchar_fd('\n', fd);
	ft_read_from_file(fd);
	close(fd);
	printf("\n");

	printf("\n------------------/ft_putstr_fd\\------------------------\n");
	fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	ft_putstr_fd("Hei! Is someone there?\n", fd);
	ft_read_from_file(fd);
	close(fd);

	printf("\n-----------------/ft_putendl_fd\\------------------------\n");
	fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	ft_putstr_fd("No! There is no one here.", fd);
	ft_read_from_file(fd);
	close(fd);
	printf("\n");

	printf("\n------------------/ft_putnbr_fd\\------------------------\n");
	fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
	ft_putnbr_fd(-123456891, fd);
	ft_read_from_file(fd);
	close(fd);
	printf("\n");

	// printf("\n---------------------/ft_lstnew\\------------------------\n");
	// char	str_lst [] = "lorem ipsum dolor sit";

	// if (!(elem = ft_lstnew(str_lst)))
	// 		ft_print_result("NULL");
	// else
	// {
	// 	if (!(elem->content))
	// 		ft_print_result("NULL");
	// 	else
	// 	{
	// 		ft_print_result(elem->content);
	// 	}
	// 	if (!(elem->next))
	// 	{
	// 		write(1, "\n", 1);
	// 		ft_print_result("NULL\n");
	// 	}
	// }

	// printf("\n---------------/ft_lstadd_front\\------------------------\n");
	// elem = ft_lstnewone(str);
	// elem2 = ft_lstnewone(str2);
	// elem3 = ft_lstnewone(str3);
	// elem4 = ft_lstnewone(str4);
	// begin = NULL;
	// begin = NULL;
	// ft_lstadd_front(&begin, elem4);
	// ft_lstadd_front(&begin, elem3);
	// ft_lstadd_front(&begin, elem2);
	// ft_lstadd_front(&begin, elem);
	// while (begin)
	// {
	// 	ft_print_result_add(begin);
	// 	begin = begin->next;
	// }
	// ft_lstclear(&elem, &ft_del);
	// ft_lstclear(&elem2, &ft_del);
	// ft_lstclear(&ele3, &ft_del);
	// ft_lstclear(&ele4, &ft_del);

	// printf("\n--------------------/ft_lstsize\\------------------------\n");

	// printf("\n--------------------/ft_lstlast\\------------------------\n");

	// printf("\n----------------/ft_lstadd_back\\------------------------\n");
	// ft_lstadd_back(&begin, elem);
	// ft_lstadd_back(&begin, elem2);
	// ft_lstadd_back(&begin, elem3);
	// ft_lstadd_back(&begin, elem4);
	// while (begin)
	// {
	// 	ft_print_result_add(begin);
	// 	begin = begin->next;
	// }

	// printf("\n------------------/ft_lstdelone\\------------------------\n");

	// printf("\n-------------------/ft_lstclear\\------------------------\n");
	// ft_lstclear(&elem3, &ft_del);
	// if (elem)
	// 	ft_print_result_del(elem);
	// else
	// 	write(1, "NULL", 4);
	// write(1, "\n", 1);
	// if (elem2)
	// 	ft_print_result_del(elem2);
	// else
	// 	write(1, "NULL", 4);
	// write(1, "\n", 1);
	// if (elem3)
	// 	ft_print_result_del(elem3);
	// else
	// 	write(1, "NULL", 4);
	// write(1, "\n", 1);
	// if (elem4)
	// {
	// 	write(1, "nb_free_done = ", 15);
	// 	nb_free_done += '0';
	// 	write(1, &nb_free_done, 1);
	// }
	// else
	// 	write(1, "NULL", 4);

	// printf("\n--------------------/ft_lstiter\\------------------------\n");

	// printf("\n---------------------/ft_lstmap\\------------------------\n");

	free(s);
	free(dest1);
	//free(dest2);
	free(dest3);
	//free(dest4);
	free(dest5);
	free(dest6);
	free(substr);
	free(joined_str);
	free(trimmed_str);
	return (0);
}
