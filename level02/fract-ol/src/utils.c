/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:14:38 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/10 17:24:00 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(void)
{
	ft_printf("┌--------------------------USAGE--------------------------┐\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Usage: ./fractol [fractal set]                         |\n");
	ft_printf("|  Fractal sets: mandelbrot, julia, burning_ship, nova    |\n");
	ft_printf("|                                                         |\n");
	help_keyboard_msg();
	help_mouse_msg();
	exit(EXIT_FAILURE);
}

void	help_keyboard_msg(void)
{
	ft_printf("|------------------------KEYBOARD-------------------------|\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Movement: ← (left arrow)                               |\n");
	ft_printf("|            → (right arrow)                              |\n");
	ft_printf("|            ↑ (up arrow)                                 |\n");
	ft_printf("|            ↓ (down arrow)                               |\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Increase color: 🟥 - Q, 🟩 - W, 🟦 - E                 |\n");
	ft_printf("|  Decrease color: 🟥 - A, 🟩 - S, 🟦 - D                 |\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Change set: 1️⃣ - Mandelbrod                             |\n");
	ft_printf("|              2️⃣ - Julia                                  |\n");
	ft_printf("|              3️⃣ - Burning Ship       ┐(￣ヘ￣)┌          |\n");
	ft_printf("|              4️⃣ - Nova                                   |\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Increase number of iterations: ➖ (minus sign)         |\n");
	ft_printf("|  Decrease number of iterations: 🟰 (equal sign)         |\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Reload Image: BACKSPACE        (シ. .)シ               |\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Lock Set [only for Julia and Nova]: L                  |\n");
	ft_printf("|                                                         |\n");
}

void	help_mouse_msg(void)
{
	ft_printf("|--------------------------MOUSE--------------------------|\n");
	ft_printf("|                                                         |\n");
	ft_printf("|  Zoom In: Mouse Wheel Down                              |\n");
	ft_printf("|  Zoom Out: Mouse Wheel Up                               |\n");
	ft_printf("|                                                         |\n");
	ft_printf("└-----------------------(─‿‿─)----------------------------┘\n");
}

void	error_msg(char *error_text, t_viewport *viewport)
{
	if (error_text)
		ft_putendl_fd(error_text, 2);
	on_destroy_event(viewport);
}
