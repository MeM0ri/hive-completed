/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:35 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 21:35:01 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_renderer(t_render *viewport, char *fractal_type)
{
	if (!viewport || !fractal_type)
		exit(EXIT_FAILURE);
	viewport->mlx = mlx_init();
	viewport->window = mlx_new_window(viewport->mlx, WIN_WIDTH, WIN_HEIGHT,
			WIN_NAME);
	viewport->image.img_ptr = mlx_new_image(viewport->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!viewport->window || !viewport->image.img_ptr)
	{
		mlx_destroy_image(viewport->mlx, viewport->image.img_ptr);
		mlx_destroy_window(viewport->mlx, viewport->window);
	}
	viewport->image.addr_ptr = mlx_get_data_addr(viewport->image.img_ptr,
			&viewport->image.bpp, &viewport->image.line_len, &viewport->image.endian);
}

void	render(t_render *viewport)
{
	mlx_clear_window(viewport->mlx, viewport->window);
	mlx_put_image_to_window(viewport->mlx, viewport->window,
		viewport->image.img_ptr, 0, 0);
}
