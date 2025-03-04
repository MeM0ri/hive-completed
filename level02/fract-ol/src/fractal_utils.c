/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:41 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/04 14:40:02 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_fractal_type(t_viewport *viewpoint, char *fractal_type)
{
	size_t	len;

	if (!viewpoint || !fractal_type)
		error_msg("[ERROR] MEMORY ERROR: can't set fractal type.\n");
	len = ft_strlen(fractal_type);
	if (ft_strncmp(MANDELBROT_STR, fractal_type, len) == 0)
		viewpoint->fractal.type = MANDELBROT;
	else if (ft_strncmp(JULIA_STR, fractal_type, len) == 0)
		viewpoint->fractal.type = JULIA;
	else if (ft_strncmp(BURNING_SHIP_STR, fractal_type, len) == 0)
		viewpoint->fractal.type = BURNING_SHIP;
	else if (ft_strncmp(NOVA_STR, fractal_type, len) == 0)
		viewpoint->fractal.type = NOVA;
	else
		help_msg();
}

void	change_fractal(int key, t_viewport *viewport)
{
	init_fractal(viewport, MANDELBROT);
	if (key == KEY_TWO)
		viewport->fractal.type = JULIA;
	else if (key == KEY_THREE)
		viewport->fractal.type = BURNING_SHIP;
	else if (key == KEY_FOUR)
		viewport->fractal.type = NOVA;
}
