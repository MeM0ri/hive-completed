/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:41 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 17:16:14 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_engine *engine)
{
	mlx_clear_window(engine->mlx, engine->window);
	mlx_put_image_to_window(engine->mlx, engine->window, engine->image.img_ptr, 0, 0);
}
