/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:35 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 16:06:05 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_engine(t_engine *engine, char *fractal_type)
{
	if (!engine || !fractal_type)
		exit(EXIT_FAILURE);
	engine->mlx = mlx_init();
	engine->window = mlx_new_window(engine->mlx, WIN_WIDTH, WIN_HEIGHT,
		WIN_NAME);
	engine->image.img_ptr = mlx_new_image(engine->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!engine->window || !engine->image.img_ptr)
	{
		mlx_destroy_image(engine->mlx, engine->image.img_ptr);
		mlx_destroy_window(engine->mlx, engine->window);
	}
	engine->image.addr_ptr = mlx_get_data_addr(engine->image.img_ptr,
		&engine->image.bpp, &engine->image.line_len, &engine->image.endian);
}
