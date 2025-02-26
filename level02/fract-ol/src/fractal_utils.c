/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:41 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/26 17:55:07 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fractal_type(t_fractal *fractal, char *fractal_type)
{
	size_t	len;

	if (!fractal || !fractal_type)
		error_msg("[ERROR] MEMORY ERROR: can't set fractal type.\n");
	len = ft_strlen(fractal_type);
	if (ft_strncmp(MANDELBROT_STR, fractal_type, len) == 0)
		fractal->type = MANDELBROT;
	else if (ft_strncmp(JULIA_STR, fractal_type, len) == 0)
		fractal->type = JULIA;
	else if (ft_strncmp(BURNING_SHIP_STR, fractal_type, len) == 0)
		fractal->type = BURNING_SHIP;
	else
		help_msg();
}
