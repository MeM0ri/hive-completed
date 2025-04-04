/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:38 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/17 16:00:08 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	thread_loop(t_thread *thread_data, t_viewport *viewport,
			t_fractal *fractal, t_complex_number c)
{
	int	i_num;
	int	x;
	int	y;
	int	start_x;
	int	end_x;

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
			set_pixel_color(viewport, (int []){x, y}, fractal->color, i_num);
		}
	}
}

void	*thread_create(void *arg)
{
	t_thread			*thread_data;
	t_viewport			*viewport;
	t_fractal			*fractal;
	t_complex_number	c;

	c.im = 0;
	c.real = 0;
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
		if (pthread_create(&render->threads[i], NULL, thread_create,
				&render->thread_data[i]) != 0)
			error_msg("[ERROR] THREAD ERROR: can't create thread.\n", viewport);
	}
	i = -1;
	while (++i < THREAD_NUM)
		pthread_join(render->threads[i], NULL);
	mlx_put_image_to_window(viewport->mlx, viewport->window,
		viewport->image.img_ptr, 0, 0);
	show_controls(viewport);
}
