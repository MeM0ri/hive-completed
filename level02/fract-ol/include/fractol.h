/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:28 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 21:39:27 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "ft_printf.h"
# include "libft.h"

/*------------------------------WIMDOW SETTINGS-------------------------------*/
# define WIN_WIDTH 720
# define WIN_HEIGHT 480
# define WIN_NAME "fract-ol"

/*-------------------------------FRACTAL TYPES--------------------------------*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

typedef struct s_image {
	void	*img_ptr;
	char	*addr_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_fractal
{
	int		type;
}				t_fractal;


typedef struct s_render
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}				t_render;


/*---------------------------------FRACTOLS-----------------------------------*/
int		main(int argc, char **argv);

/*---------------------------------FRACTALS-----------------------------------*/

/*----------------------------------RENDER------------------------------------*/
void	init_renderer(t_render *viewport, char *fractal_type);
void	render(t_render *viewport);

/*-----------------------------------UTILS------------------------------------*/


#endif
