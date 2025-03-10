/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:32 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/10 16:30:25 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_viewport	viewport;

	if (argc != 2 && argc != 4)
		help_msg();
	if (argc == 2)
		init_viewport(&viewport, argv[1], "\0", "\0");
	else
		init_viewport(&viewport, argv[1], argv[2], argv[3]);
	thread_manager(&viewport);
	mlx_key_hook(viewport.window, on_key_hook_event, &viewport);
	mlx_mouse_hook(viewport.window, on_mouse_hook_event, &viewport);
	mlx_hook(viewport.window, 6, 1L << 6, on_mousemove_event, &viewport);
	mlx_hook(viewport.window, 17, 0, on_destroy_event, &viewport);
	mlx_loop(viewport.mlx);
	exit(EXIT_SUCCESS);
}
