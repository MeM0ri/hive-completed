/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:38 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/04 18:01:05 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*thread_create(void *viewport)
{
	t_thread			*t;
	t_fractal			*fractal;
	t_complex_number	c;
	int					x;
	int					y;
	//int					i_num;

	t = (t_thread *)viewport;
	fractal = &t->viewport->fractal;
	x = (WIDTH / THREAD_NUM * t->id);
	while (x < HEIGHT / THREAD_NUM * (t->id + 1))
	{
		if (fractal->type != JULIA && fractal->type != NOVA)
			c.real = (x / fractal->zoom) + fractal->offset_x;
		else if (!fractal->is_julia_locked)
			c.real = (fractal->mouse_x / fractal->zoom) + fractal->offset_x;
		y = -1;
		while (y < HEIGHT)
		{
			calc_fractal(fractal, &c, x, y);
		}
			x++;
	}
	return (NULL);
}

void	thread_manager(t_viewport *viewport)
{
	t_render	*render;
	int			i;

	mlx_clear_window(viewport->mlx, viewport->window);
	render = &viewport->render;
	i = -1;
	while (++i < THREAD_NUM)
	{
		render->thread_data[i].id = i;
		render->thread_data[i].viewport = viewport;
		pthread_create(render->threads + 1, NULL, thread_create, &(render->thread_data[i]));
	}
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(render->threads[i], NULL);
	draw(viewport);
}

void	draw(t_viewport *viewport)
{
	int x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			set_pixel_color(viewport, x, y, (viewport->fractal.iteration_num * viewport->fractal.color));
	}
	mlx_put_image_to_window(viewport->mlx, viewport->window, viewport->image.img_ptr, 0, 0);
}
