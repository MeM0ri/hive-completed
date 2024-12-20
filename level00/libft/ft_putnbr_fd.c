/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:54:28 by alfokin           #+#    #+#             */
/*   Updated: 2024/11/06 15:20:39 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_check(int n, int fd, unsigned int *nbr)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		*nbr = (unsigned int)(-n);
		write(fd, "-", 1);
	}
	else
		*nbr = (unsigned int)n;
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			buffer[12];
	int				i;
	unsigned int	nbr;

	nbr = 0;
	if (ft_int_check(n, fd, &nbr))
		return ;
	i = 0;
	while (nbr > 0)
	{
		buffer[i++] = '0' + (nbr % 10);
		nbr /= 10;
	}
	while (i > 0)
		write(fd, &buffer[--i], 1);
}
