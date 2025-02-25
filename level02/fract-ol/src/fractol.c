/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:32 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 21:35:01 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_render	viewport;

	if (argc != 2)
	{
		ft_printf("Usage: %s [fractal]\n", argv[0]);
		ft_printf("Fractals: mandelbrot, julia, burningship\n");
		exit(EXIT_FAILURE);
	}
	init_renderer(&viewport, argv[1]);
	render(&viewport);
	mlx_loop(viewport.mlx);
	exit(EXIT_SUCCESS);
}
