/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:27 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/05 16:13:26 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color(t_viewport *viewport, int key)
{
	if (key == KEY_Q)
		viewport->fractal.color.value += 0x110000;
	else if (key == KEY_W)
		viewport->fractal.color.value += 0x001100;
	else if (key == KEY_E)
		viewport->fractal.color.value += 0x000011;
	else if (key == KEY_A)
		viewport->fractal.color.value -= 0x110000;
	else if (key == KEY_S)
		viewport->fractal.color.value -= 0x001100;
	else if (key == KEY_D)
		viewport->fractal.color.value -= 0x000011;
}

void	change_view(t_viewport *viewport, int key)
{
	t_fractal	*fractal;

	fractal = &viewport->fractal;
	if (key == KEY_UP)
		fractal->offset_y -= VIEW_CHANGE_FACTOR / fractal->zoom;
	else if (key == KEY_DOWN)
		fractal->offset_y += VIEW_CHANGE_FACTOR / fractal->zoom;
	else if (key == KEY_LEFT)
		fractal->offset_x -= VIEW_CHANGE_FACTOR / fractal->zoom;
	else if (key == KEY_RIGHT)
		fractal->offset_x += VIEW_CHANGE_FACTOR / fractal->zoom;
}

void	change_iter(t_viewport *viewport, int key)
{
	if (key == KEY_MINUS)
		viewport->fractal.iteration_num += 10;
	else if (key == KEY_EQUAL)
		viewport->fractal.iteration_num -= 10;
}
