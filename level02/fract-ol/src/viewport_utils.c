/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:27 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/06 14:43:24 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel_color(t_viewport *viewport, int coord[2], unsigned int color,
			int iter_num)
{
	int	line_len;
	int	pixel_bits;
	int	offset;
	int	x;
	int	y;

	x = coord[0];
	y = coord[1];
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	line_len = viewport->image.line_len;
	pixel_bits = viewport->image.bpp;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	if (iter_num >= viewport->fractal.iteration_num)
		*(unsigned int *)(viewport->image.addr_ptr + offset) = 0x00000000;
	else
		*(unsigned int *)(viewport->image.addr_ptr + offset) = iter_num * color;
}

void	change_color(t_viewport *viewport, int key)
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
