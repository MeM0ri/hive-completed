/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:41:27 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/26 17:43:09 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pixel_color(t_render *viewport, int x, int y, int color)
{
	int	line_len;
	int	pixel_bits;
	int	offset;

	if (x < 0 || x >= WIN_HEIGHT || y < 0 || y >= WIN_WIDTH)
		return ;
	line_len = viewport->image.line_len;
	pixel_bits = viewport->image.bpp;
	offset = (y * line_len) + ((pixel_bits / 8) * x);
	*(unsigned int *)(viewport->image.addr_ptr + offset) = color;
}
