/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:28 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/26 20:23:05 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>
# include <mlx.h>
# include "ft_printf.h"
# include "libft.h"

/*------------------------------WIMDOW SETTINGS-------------------------------*/
# define WIN_WIDTH 500
# define WIN_HEIGHT 500
# define WIN_NAME "fract-ol"

/*-------------------------------FRACTAL TYPES--------------------------------*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3

/*------------------------------FRACTAL STRINGS-------------------------------*/
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"

/*------------------------------FRACTAL SETTINGS------------------------------*/
# define DEFAULT_ITERATIONS 256
# define DEFAULT_COLOR 265
# define ZOOM_FACTOR 4

typedef struct s_image {
	void	*img_ptr;
	char	*addr_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_fractal
{
	int			type;
	int			iteration_num;
	bool		is_julia_locked;
	uint32_t	color;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
	double		offset_x;
	double		offset_y;
}				t_fractal;


typedef struct s_render
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}				t_render;

typedef struct s_complex_number
{
	double	real_part;
	double	imaginary_part;
}				t_complex_number;


/*---------------------------------FRACTOL------------------------------------*/
int		main(int argc, char **argv);

/*---------------------------------FRACTALS-----------------------------------*/
int		calc_mandelbrot(t_fractal *fractal, t_complex_number *c);
int		calc_julia(t_fractal *fractal, t_complex_number *c, int x, int y);
int		calc_burning_ship(t_fractal *fractal, t_complex_number *c);

/*------------------------------FRACTAL_UTILS---------------------------------*/
void	set_fractal_type(t_render *viewpoint, char *fractal_type);

/*---------------------------------VIEWPORT-----------------------------------*/
void	init_viewport(t_render *viewport, char *fractal_type);
void	init_fractal(t_render *viewpoint, int fractal_type);
void	render(t_render *viewport);

/*------------------------------VIEWPORT_UTILS--------------------------------*/
void	set_pixel_color(t_render *viewport, int x, int y, int color);

/*-----------------------------------UTILS------------------------------------*/
void	help_msg(void);
void	error_msg(char *error_text);

#endif
