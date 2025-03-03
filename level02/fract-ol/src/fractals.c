/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:41 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/03 13:24:30 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(t_fractal *fractal, t_complex_number *c)
{
	double				re_temp;
	t_complex_number	z;
	int					i;

	i = -1;
	z.real = 0;
	z.im = 0;
	while ((z.real * z.real + z.im * z.im) < 4 && ++i < fractal->iteration_num)
	{
		re_temp = z.real * z.real - z.im * z.im + c->real;
		z.im = 2 * z.real * z.im + c->im;
		z.real = re_temp;
	}
	return (i);
}

int	calc_julia(t_fractal *fractal, t_complex_number *c, int x, int y)
{
	double				re_temp;
	t_complex_number	z;
	int					i;

	i = -1;
	z.real = (x / fractal->zoom) + fractal->offset_x;
	z.im = (y / fractal->zoom) + fractal->offset_y;
	while ((z.real * z.real + z.im * z.im) < 4 && ++i < fractal->iteration_num)
	{
		re_temp = z.real * z.real - z.im * z.im + c->real;
		z.im = 2 * z.real * z.im + c->im;
		z.real = re_temp;
	}
	return (i);
}

int	calc_burning_ship(t_fractal *fractal, t_complex_number *c)
{
	double				re_temp;
	t_complex_number	z;
	int					i;

	i = -1;
	z.real = 0;
	z.im = 0;
	while ((z.real * z.real + z.im * z.im) < 4 && ++i < fractal->iteration_num)
	{
		re_temp = z.real * z.real - z.im * z.im + c->real;
		z.im = fabs(2 * z.real * z.im) + c->im;
		z.real = fabs(re_temp);
	}
	return (i);
}
