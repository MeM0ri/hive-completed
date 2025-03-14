/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:03:15 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/10 16:38:22 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	on_key_hook_event(int key, t_viewport *viewport)
{
	t_fractal	*f;

	f = &viewport->fractal;
	if ((key >= KEY_A && key <= KEY_E) || (key >= KEY_Q && key <= KEY_W))
		change_color(viewport, key);
	else if (key >= KEY_LEFT && key <= KEY_DOWN)
		change_view(viewport, key);
	else if (key >= KEY_ONE && key <= KEY_FOUR)
		change_fractal(key, viewport);
	else if (key == KEY_MINUS || key == KEY_EQUAL)
		change_iter(viewport, key);
	else if (key == KEY_L && (f->type == JULIA || f->type == NOVA))
	{
		f->is_locked ^= 1;
		f->c.real = (f->mouse_x / f->zoom) + f->offset_x;
		f->c.im = (f->mouse_y / f->zoom) + f->offset_y;
	}
	else if (key == KEY_K)
		viewport->is_show_controls ^= 1;
	else if (key == KEY_BACKSPACE)
		init_fractal(viewport, f->type);
	else if (key == KEY_ESC)
		on_destroy_event(viewport);
	thread_manager(viewport);
	return (0);
}

int	on_mouse_hook_event(int key, int x, int y, t_viewport *viewport)
{
	t_fractal	*fr;

	fr = &viewport->fractal;
	if (key == MOUSE_SCRL_DOWN)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom * 1.1));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom * 1.1));
		fr->zoom *= 1.1;
		fr->iteration_num++;
	}
	else if (key == MOUSE_SCRL_UP)
	{
		fr->offset_x = (x / fr->zoom + fr->offset_x) - (x / (fr->zoom / 1.1));
		fr->offset_y = (y / fr->zoom + fr->offset_y) - (y / (fr->zoom / 1.1));
		fr->zoom /= 1.1;
		fr->iteration_num--;
	}
	thread_manager(viewport);
	return (0);
}

int	on_mousemove_event(int x, int y, t_viewport *viewport)
{
	if ((viewport->fractal.type != JULIA && viewport->fractal.type != NOVA)
		|| viewport->fractal.is_locked)
		return (0);
	viewport->fractal.mouse_x = x;
	viewport->fractal.mouse_y = y;
	thread_manager(viewport);
	return (0);
}

int	on_destroy_event(t_viewport *viewport)
{
	mlx_destroy_image(viewport->mlx, viewport->image.img_ptr);
	mlx_destroy_window(viewport->mlx, viewport->window);
	mlx_destroy_display(viewport->mlx);
	free(viewport->mlx);
	exit(EXIT_SUCCESS);
}
