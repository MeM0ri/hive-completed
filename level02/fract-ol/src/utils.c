/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:38 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/04 00:27:58 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(void)
{
	ft_printf("Usage: ./fractol [fractal set]\n");
	ft_printf("Fractal sets: mandelbrot, julia, burning_ship, nova\n");
	exit(EXIT_FAILURE);
}

void	error_msg(char *error_text)
{
	if (error_text)
		ft_putendl_fd(error_text, 2);
	exit(EXIT_FAILURE);
}
