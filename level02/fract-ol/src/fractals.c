/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:41 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/27 16:27:15 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_mandelbrot(t_fractal *fractal, t_complex_number *c)
{
	double				re_temp;
	t_complex_number	z;
	int					i;

	i = -1;
	z.real_part = 0;
	z.imaginary_part = 0;
	while ((pow(z.real_part, 2) + pow(z.imaginary_part, 2)) < 4 && ++i < fractal->iteration_num)
	{
		re_temp = pow(z.real_part, 2) - pow(z.imaginary_part, 2) + c->real_part;
		z.imaginary_part = 2 * z.real_part * z.imaginary_part + c->imaginary_part;
		z.real_part = re_temp;
	}
	return (i);
}

int	calc_julia(t_fractal *fractal, t_complex_number *c, int x, int y)
{
	double		re_temp;
	t_complex_number	z;
	int			i;

	i = -1;
	z.real_part = (x / fractal->zoom) + fractal->offset_x;
	z.imaginary_part = (y / fractal->zoom) + fractal->offset_y;
	while ((pow(z.real_part, 2) + pow(z.imaginary_part, 2)) < 4 && ++i < fractal->iteration_num)
	{
		re_temp = pow(z.real_part, 2) - pow(z.imaginary_part, 2) + c->real_part;
		z.imaginary_part = 2 * z.real_part * z.imaginary_part + c->imaginary_part;
		z.real_part = re_temp;
	}
	return (i);
}

int	calc_burning_ship(t_fractal *fractal, t_complex_number *c)
{
	double		re_temp;
	t_complex_number	z;
	int			i;

	i = -1;
	z.real_part = 0;
	z.imaginary_part = 0;
	while ((pow(z.real_part, 2) + pow(z.imaginary_part, 2)) < 4 && ++i < fractal->iteration_num)
	{
		re_temp = pow(z.real_part, 2) - pow(z.imaginary_part, 2) + c->real_part;
		z.imaginary_part = fabs(2 * z.real_part * z.imaginary_part) + c->imaginary_part;
		z.real_part = fabs(re_temp);
	}
	return (i);
}
