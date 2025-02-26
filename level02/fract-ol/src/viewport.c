/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:35 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/26 20:23:57 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_viewport(t_render *viewport, char *fractal_type)
{
	if (!viewport || !fractal_type)
		exit(EXIT_FAILURE);
	init_fractal(viewport, MANDELBROT);
	set_fractal_type(viewport, fractal_type);
	viewport->mlx = mlx_init();
	if (!viewport->mlx)
		error_msg("[ERROR] MLX ERROR: can't initialize mlx.\n");
	viewport->window = mlx_new_window(viewport->mlx, WIN_WIDTH, WIN_HEIGHT,
			WIN_NAME);
	viewport->image.img_ptr = mlx_new_image(viewport->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!viewport->window || !viewport->image.img_ptr)
	{
		mlx_destroy_image(viewport->mlx, viewport->image.img_ptr);
		mlx_destroy_window(viewport->mlx, viewport->window);
		error_msg("[ERROR] MLX ERROR: can't create window.\n");
	}
	viewport->image.addr_ptr = mlx_get_data_addr(viewport->image.img_ptr,
			&viewport->image.bpp, &viewport->image.line_len,
			&viewport->image.endian);
}

void	init_fractal(t_render *viewpoint, int fractal_type)
{
	viewpoint->fractal.type = fractal_type;
	viewpoint->fractal.iteration_num = DEFAULT_ITERATIONS;
	viewpoint->fractal.color = DEFAULT_COLOR;
	viewpoint->fractal.zoom = WIN_WIDTH / ZOOM_FACTOR;
	viewpoint->fractal.mouse_x = 0;
	viewpoint->fractal.mouse_y = 0;
	viewpoint->fractal.offset_x = -2;
	viewpoint->fractal.offset_y = -2;
	viewpoint->fractal.is_julia_locked = false;
}

int	calc_fractal(t_fractal *fractal, t_complex_number *c, int x, int y)
{
	int	iteration_num;

	iteration_num = 0;
	if (fractal->type != JULIA)
		c->imaginary_part = (y / fractal->zoom) + fractal->offset_y;
	else if (!fractal->is_julia_locked)
		c->imaginary_part = (fractal->mouse_y / fractal->zoom) + fractal->offset_y;
	if (fractal->type == MANDELBROT)
		iteration_num = calc_mandelbrot(fractal, c);
	else if (fractal->type == JULIA)
		iteration_num = calc_julia(fractal, c, x, y);
	else if (fractal->type == BURNING_SHIP)
		iteration_num = calc_burning_ship(fractal, c);
	return (iteration_num);
}

void	render(t_render *viewport)
{
	t_complex_number	c;
	t_fractal			*fractal;
	int					x_axis;
	int					y_axis;
	int					iteration_num;

	mlx_clear_window(viewport->mlx, viewport->window);
	fractal = &viewport->fractal;
	x_axis = -1;
	while (++x_axis < WIN_WIDTH)
	{
		if (fractal->type == JULIA)
			c.real_part = (x_axis / fractal->zoom) * fractal->offset_x;
		else if (!fractal->is_julia_locked)
			c.real_part = (fractal->mouse_x / fractal->zoom) + fractal->offset_x;
		y_axis = -1;
		while (++y_axis < WIN_HEIGHT)
		{
			iteration_num = calc_fractal(fractal, &c, x_axis, y_axis);
			set_pixel_color(viewport, x_axis, y_axis, (iteration_num * fractal->color));
		}
	}
	mlx_put_image_to_window(viewport->mlx, viewport->window,
		viewport->image.img_ptr, 0, 0);
}
