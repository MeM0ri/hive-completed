/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:35 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/06 16:42:19 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_viewport(t_viewport *viewport, char *fr_type, char *x, char *y)
{
	if (!viewport || !fr_type)
		exit(EXIT_FAILURE);
	init_fractal(viewport, MANDELBROT);
	set_fractal_type(viewport, fr_type);
	if ((viewport->fractal.type == JULIA || viewport->fractal.type == NOVA)
		&& (ft_strncmp(x, "\0", 2) != 0 && ft_strncmp(x, "\0", 2) != 0))
	{
			viewport->fractal.is_locked = true;
			viewport->fractal.mouse_x = ft_atoi(x);
			viewport->fractal.mouse_y = ft_atoi(y);
	}
	viewport->mlx = mlx_init();
	if (!viewport->mlx)
		error_msg("[ERROR] MLX ERROR: can't initialize mlx.\n");
	viewport->window = mlx_new_window(viewport->mlx, WIDTH, HEIGHT,
			WIN_NAME);
	viewport->image.img_ptr = mlx_new_image(viewport->mlx, WIDTH, HEIGHT);
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

void	init_fractal(t_viewport *viewpoint, int fractal_type)
{
	viewpoint->fractal.type = fractal_type;
	viewpoint->fractal.iteration_num = DEFAULT_ITERATIONS;
	viewpoint->fractal.is_locked = false;
	viewpoint->fractal.color = DEFAULT_COLOR;
	viewpoint->fractal.zoom = (WIDTH * HEIGHT) / ZOOM_FACTOR;
	viewpoint->fractal.mouse_x = 0;
	viewpoint->fractal.mouse_y = 0;
	viewpoint->fractal.offset_x = -3.75;
	viewpoint->fractal.offset_y = -2.10;
}

int	calc_fractal(t_fractal *fractal, t_complex_number *c, int x, int y)
{
	int	iteration_num;

	iteration_num = 0;
	if (fractal->type != JULIA && fractal->type != NOVA)
		c->im = (y / fractal->zoom) + fractal->offset_y;
	//else if (!fractal->is_locked)
	//	c->im = (fractal->mouse_y / fractal->zoom) + fractal->offset_y;
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
