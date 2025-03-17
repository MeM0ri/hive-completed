/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:35 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/17 14:19:30 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_viewport(t_viewport *view, char *fr_type, char *x, char *y)
{
	if (!view || !fr_type)
		exit(EXIT_FAILURE);
	init_fractal(view, MANDELBROT);
	set_fractal_type(view, fr_type);
	if ((view->fractal.type == JULIA || view->fractal.type == NOVA)
		&& (ft_strncmp(x, "\0", 2) != 0 && ft_strncmp(y, "\0", 2) != 0))
	{
		view->fractal.is_locked = true;
		view->fractal.c.real = ft_atod(x);
		view->fractal.c.im = ft_atod(y);
	}
	view->mlx = mlx_init();
	if (!view->mlx)
		error_msg("[ERROR] MLX ERROR: can't initialize mlx.\n", view);
	view->window = mlx_new_window(view->mlx, WIDTH, HEIGHT, WIN_NAME);
	view->image.img_ptr = mlx_new_image(view->mlx, WIDTH, HEIGHT);
	if (!view->window || !view->image.img_ptr)
		error_msg("[ERROR] MLX ERROR: can't create window.\n", view);
	view->image.addr_ptr = mlx_get_data_addr(view->image.img_ptr,
			&view->image.bpp, &view->image.line_len, &view->image.endian);
	view->is_show_controls = false;
}

void	init_fractal(t_viewport *viewport, int fractal_type)
{
	viewport->fractal.type = fractal_type;
	viewport->fractal.iteration_num = DEFAULT_ITERATIONS;
	viewport->fractal.is_locked = false;
	viewport->fractal.color = DEFAULT_COLOR;
	viewport->fractal.zoom = (WIDTH * HEIGHT) / ZOOM_FACTOR;
	viewport->fractal.mouse_x = 0;
	viewport->fractal.mouse_y = 0;
	viewport->fractal.offset_x = -3.75;
	viewport->fractal.offset_y = -2.10;
	viewport->fractal.c.real = 0;
	viewport->fractal.c.im = 0;
}

int	calc_fractal(t_fractal *fractal, t_complex_number *c, int x, int y)
{
	int	iteration_num;

	iteration_num = 0;
	if (fractal->type == MANDELBROT)
		iteration_num = calc_mandelbrot(fractal, c);
	else if (fractal->type == JULIA)
		iteration_num = calc_julia(fractal, c, x, y);
	else if (fractal->type == BURNING_SHIP)
		iteration_num = calc_burning_ship(fractal, c);
	else if (fractal->type == NOVA)
		iteration_num = calc_nova(fractal, c, x, y);
	return (iteration_num);
}
