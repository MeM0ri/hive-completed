/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:27 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/03 13:23:10 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel_color(t_render *viewport, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	line_len = viewport->image.line_len;
	pixel_bits = viewport->image.bpp;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(viewport->image.addr_ptr + offset) = color;
}

void	change_color(t_render *viewport, int key)
{
	if (key == KEY_Q)
		viewport->fractal.color += 0x110000;
	else if (key == KEY_W)
		viewport->fractal.color += 0x001100;
	else if (key == KEY_E)
		viewport->fractal.color += 0x000011;
	else if (key == KEY_A)
		viewport->fractal.color -= 0x110000;
	else if (key == KEY_S)
		viewport->fractal.color -= 0x001100;
	else if (key == KEY_D)
		viewport->fractal.color -= 0x000011;
}

void	change_view(t_render *viewport, int key)
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
