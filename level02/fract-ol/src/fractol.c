/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:32 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 14:01:18 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	// if (argc != 2)
	// {
	// 	ft_printf("Usage: %s [fractal]\n", argv[0]);
	// 	ft_printf("Fractals: mandelbrot, julia, burningship\n");
	// 	exit(EXIT_FAILURE);
	// }
	// if (ft_strcmp(argv[1], "mandelbrot") == 0)
	// 	mandelbrot();
	// else if (ft_strcmp(argv[1], "julia") == 0)
	// 	julia();
	// else if (ft_strcmp(argv[1], "burningship") == 0)
	// 	burningship();
	// else
	// {
	// 	ft_printf("Usage: %s [fractal]\n", argv[0]);
	// 	ft_printf("Fractals: mandelbrot, julia, burningship\n");
	// 	exit(EXIT_FAILURE);
	// }
	exit(EXIT_SUCCESS);
}
