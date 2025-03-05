/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:50:12 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/05 16:32:57 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	color_lerp(t_color c1, t_color c2, double p)
{
	t_color	c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.a = 0x00;
	c.rgba.b = (unsigned char)((1 - p) * c1.rgba.b + p * c2.rgba.b);
	c.rgba.g = (unsigned char)((1 - p) * c1.rgba.g + p * c2.rgba.g);
	c.rgba.r = (unsigned char)((1 - p) * c1.rgba.r + p * c2.rgba.r);
	return (c);
}

t_color	get_linear_color(double i, int max)
{
	double	t;
	t_color	color1;
	t_color	color2;

	t = i / (double)max;
	color1.value = 0x000080;
	color2.value = 0x00BFFF;
	return (color_lerp(color1, color2, t));
}

t_color	get_smooth_color(t_pixel p, int max)
{
	double	i;
	double	zn;
	double	nu;

	zn = log(p.c.real * p.c.real + p.c.im * p.c.im) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.iter_num + 1 - nu;
	if (i < 0)
		i = 0;
	return (get_linear_color(i, max));
}

int	get_color(t_viewport *viewport, t_pixel p)
{
	if (p.iter_num >= viewport->fractal.iteration_num)
		return (0x000000);
	if (viewport->fractal.is_color_smooth)
		return (get_smooth_color(p, viewport->fractal.iteration_num).value);
	return (get_linear_color((double)p.iter_num,
			viewport->fractal.iteration_num).value);
}

void	set_pixel_color(t_viewport *viewport, int x, int y, int color)
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
