/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:12:00 by alfokin           #+#    #+#             */
/*   Updated: 2024/10/22 00:11:40 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_num(int num)
{
	if (num == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_print_num(147483648);
	}
	if (num < 0)
		num -= num;
	if (num > 10)
		ft_print_num(num / 10);
	ft_putchar(num % 10 + '0');
}
