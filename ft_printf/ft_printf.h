/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:47:42 by alfokin           #+#    #+#             */
/*   Updated: 2024/12/09 00:47:42 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *s);
void ft_putchar(char c);
void ft_putstr(char *s);
void ft_putnbr(int n);
void ft_putnbr_base(int n, int base);
