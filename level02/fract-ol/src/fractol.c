/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:32 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/24 19:57:32 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: %s [fractal]\n", argv[0]);
		ft_printf("Fractals: mandelbrot, julia, burningship\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		mandelbrot();
	else if (ft_strcmp(argv[1], "julia") == 0)
		julia();
	else if (ft_strcmp(argv[1], "burningship") == 0)
		burningship();
	else
	{
		ft_printf("Usage: %s [fractal]\n", argv[0]);
		ft_printf("Fractals: mandelbrot, julia, burningship\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
