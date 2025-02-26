/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:38 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/26 16:37:36 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(void)
{
	ft_printf("Usage: ./fractol [fractal set]\n");
	ft_printf("Fractal sets: mandelbrot, julia, burning_ship\n");
	exit(EXIT_FAILURE);
}

void	error_msg(char *error_text)
{
	if (error_text)
		ft_putendl_fd(error_text, 2);
	exit(EXIT_FAILURE);
}
