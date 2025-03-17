/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:32:45 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/17 13:15:24 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_controls(t_viewport *viewport)
{
	int	x;
	int	y;
	int	pad;

	x = 20;
	y = 20;
	pad = 20;
	if (viewport->is_show_controls)
	{
		mlx_string_put(viewport->mlx, viewport->window, x, y += pad, 0xf7b079,
			"|--------------------------KEYBOARD---------------------------|");
		mlx_string_put(viewport->mlx, viewport->window, x, y += pad, 0xfafafa,
			"|                                                             |");
		mlx_string_put(viewport->mlx, viewport->window, x, y += pad, 0xfafafa,
			"|  Movement: arrows                                           |");
		mlx_string_put(viewport->mlx, viewport->window, x, y += pad, 0xfafafa,
			"|                                                             |");
		show_rest_of_keyboard(viewport, &x, &y, pad);
		show_rest_of_mouse(viewport, &x, &y, pad);
	}
}

void	show_rest_of_keyboard(t_viewport *viewport, int *x, int *y, int pad)
{
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Increase color: Q (r), W (g), E (b)                        |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Decrease color: A (r), S (g), D (b)                        |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Change set: 1 - Mandelbrod                                 |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|              2 - Julia                                      |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|              3 - Burning Ship                               |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|              4 - Nova                                       |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Increase number of iterations: minus sign (-)              |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Decrease number of iterations: equal sign (=)              |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
}

void	show_rest_of_mouse(t_viewport *viewport, int *x, int *y, int pad)
{
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Reload Image: BACKSPACE                                    |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Lock Set [only for Julia and Nova]: L                      |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xf7b079,
		"|----------------------------MOUSE----------------------------|");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Zoom In: Mouse Wheel Down                                  |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|  Zoom Out: Mouse Wheel Up                                   |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xfafafa,
		"|                                                             |");
	mlx_string_put(viewport->mlx, viewport->window, *x, *y += pad, 0xf7b079,
		"|-------------------------------------------------------------|");
}
