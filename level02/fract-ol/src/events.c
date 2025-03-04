/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:03:15 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/04 00:42:59 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	on_key_hook_event(int key, t_render *viewport)
{
	if ((key >= KEY_A && key <= KEY_E) || (key >= KEY_Q && key <= KEY_W))
		change_color(viewport, key);
	else if (key >= KEY_LEFT && key <= KEY_DOWN)
		change_view(viewport, key);
	else if (key >= KEY_ONE && key <= KEY_FOUR)
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
	t_fractal	*fr;

	fr = &viewport->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.1));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.1));
		fr->zoom *= 1.1;
		if (fr->iteration_num < DEFAULT_ITERATIONS)
			fr->iteration_num++;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.1));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.1));
		fr->zoom /= 1.1;
		if (fr->iteration_num > DEFAULT_ITERATIONS)
			fr->iteration_num--;
	}
	render(viewport);
	return (0);
}

int	on_mousemove_event(int x, int y, t_render *viewport)
{
	if ((viewport->fractal.type != JULIA && viewport->fractal.type != NOVA)
		|| viewport->fractal.is_julia_locked)
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
