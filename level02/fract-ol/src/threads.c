/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:38 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/05 16:06:11 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thread_loop(t_thread *thread_data, t_viewport *viewport,
			t_fractal *fractal, t_complex_number c)
{
	int					i_num;
	int					x;
	int					y;
	int					start_x;
	int					end_x;

	start_x = (WIDTH / THREAD_NUM) * thread_data->id;
	if (thread_data->id == THREAD_NUM - 1)
		end_x = WIDTH;
	else
		end_x = start_x + (WIDTH / THREAD_NUM);
	x = start_x - 1;
	while (++x < end_x)
	{
		calculate_c_real(&c, fractal, x);
		y = -1;
		while (++y < HEIGHT)
		{
			calculate_c_im(&c, fractal, y);
			i_num = calc_fractal(fractal, &c, x, y);
			set_pixel_color(viewport, x, y,
				get_color(viewport, (t_pixel){.iter_num = i_num, .c = c}));
		}
	}
}

void	*thread_create(void *arg)
{
	t_thread			*thread_data;
	t_viewport			*viewport;
	t_fractal			*fractal;
	t_complex_number	c;

	thread_data = (t_thread *)arg;
	viewport = thread_data->viewport;
	fractal = &viewport->fractal;
	thread_loop(thread_data, viewport, fractal, c);
	return (NULL);
}

void	thread_manager(t_viewport *viewport)
{
	t_render	*render;
	int			i;

	render = &viewport->render;
	mlx_clear_window(viewport->mlx, viewport->window);
	i = -1;
	while (++i < THREAD_NUM)
	{
		render->thread_data[i].id = i;
		render->thread_data[i].viewport = viewport;
		pthread_create(&render->threads[i], NULL, thread_create,
			&render->thread_data[i]);
	}
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(render->threads[i], NULL);
	mlx_put_image_to_window(viewport->mlx, viewport->window,
		viewport->image.img_ptr, 0, 0);
}
