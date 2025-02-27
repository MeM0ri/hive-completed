/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:03:15 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/27 18:11:49 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	on_key_hook_event(int key, t_render *viewport)
{
	if ((key >= KEY_A && key <= KEY_H) || (key >= KEY_Q && key <= KEY_Y))
		change_color(viewport, key);
	else if (key >= KEY_LEFT && key <= KEY_DOWN)
		change_view(viewport, key);
	else if (key >= KEY_ONE && key <= KEY_THREE)
		change_fractal(key, viewport);
	else if (key == KEY_L && viewport->fractal.type == JULIA)
		viewport->fractal.is_julia_locked ^= 1;
	else if (key == KEY_BACKSPACE)
		init_fractal(viewport, viewport->fractal.type);
	else if (key == KEY_ESC)
		on_destroy_event(viewport);
	render(viewport);
	return (0);
}

int	on_mouse_hook_event(int key, int x, int y, t_render *viewport)
{
	t_fractal	*fractal;

	fractal = &viewport->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom * 1.1));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom * 1.1));
		fractal->zoom *= 1.1;
		if (fractal->iteration_num < DEFAULT_ITERATIONS)
			fractal->iteration_num++;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fractal->offset_x = (x / fractal->zoom + fractal->offset_x) - (x / (fractal->zoom / 1.1));
		fractal->offset_y = (y / fractal->zoom + fractal->offset_y) - (y / (fractal->zoom / 1.1));
		fractal->zoom /= 1.1;
		if (fractal->iteration_num > DEFAULT_ITERATIONS)
			fractal->iteration_num--;
	}
	render(viewport);
	return (0);
}

int	on_mousemove_event(int x, int y, t_render *viewport)
{
	if (viewport->fractal.type != JULIA || viewport->fractal.is_julia_locked)
		return (0);
	viewport->fractal.mouse_x = x;
	viewport->fractal.mouse_y = y;
	render(viewport);
	return (0);
}

int	on_destroy_event(t_render *viewport)
{
	mlx_destroy_image(viewport->mlx, viewport->image.img_ptr);
	mlx_destroy_window(viewport->mlx, viewport->window);
	exit(EXIT_SUCCESS);
}
