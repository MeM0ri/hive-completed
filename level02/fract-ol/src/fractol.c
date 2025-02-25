/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:32 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 17:19:43 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_engine	engine;

	if (argc != 2)
	{
		ft_printf("Usage: %s [fractal]\n", argv[0]);
		ft_printf("Fractals: mandelbrot, julia, burningship\n");
		exit(EXIT_FAILURE);
	}
	init_engine(&engine, argv[1]);
	draw(&engine);
	mlx_loop(engine.mlx);
	exit(EXIT_SUCCESS);
}
