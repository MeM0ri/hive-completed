/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:32 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/27 16:48:43 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_render	viewport;

	if (argc != 2)
		help_msg();
	init_viewport(&viewport, argv[1]);
	render(&viewport);
	mlx_key_hook(viewport.window, on_key_hook_event, &viewport);
	mlx_mouse_hook(viewport.window, on_mouse_hook_event, &viewport);
	mlx_hook(viewport.window, 6, 1L << 6, on_mousemove_event, &viewport);
	mlx_hook(viewport.window, 17, 0, on_destroy_event, &viewport);
	mlx_loop(viewport.mlx);
	exit(EXIT_SUCCESS);
}
