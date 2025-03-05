/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:28 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/05 16:27:20 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*---------------------------------INCLUDES-----------------------------------*/
# include <stdlib.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include "ft_printf.h"
# include "libft.h"
# include "keys.h"

/*------------------------------WIMDOW SETTINGS-------------------------------*/
# define WIDTH 1920
# define HEIGHT 1080
# define WIN_NAME "fract-ol"
# define THREAD_NUM 32

/*-------------------------------FRACTAL TYPES--------------------------------*/
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define NOVA 4

/*------------------------------FRACTAL STRINGS-------------------------------*/
# define MANDELBROT_STR "mandelbrot"
# define JULIA_STR "julia"
# define BURNING_SHIP_STR "burning_ship"
# define NOVA_STR "nova"

/*------------------------------FRACTAL SETTINGS------------------------------*/
# define DEFAULT_ITERATIONS 100
# define DEFAULT_COLOR 0x000080
# define ZOOM_FACTOR 8000
# define VIEW_CHANGE_FACTOR 30

/*-----------------------------FRACTOL STRUCTURES-----------------------------*/
typedef struct s_viewport	t_viewport;

typedef struct s_complex_number
{
	double	real;
	double	im;
}				t_complex_number;

typedef struct s_thread
{
	int			id;
	t_viewport	*viewport;
}				t_thread;

typedef struct s_render
{
	pthread_t	threads[THREAD_NUM];
	t_thread	thread_data[THREAD_NUM];
}				t_render;

typedef struct s_image {
	void	*img_ptr;
	char	*addr_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef struct s_pixel
{
	int					iter_num;
	t_complex_number	c;
}				t_pixel;

// typedef struct s_rgba
// {
// 	uint8_t	b;
// 	uint8_t	g;
// 	uint8_t	r;
// 	uint8_t	a;
// }				t_rgba;

typedef union u_color
{
	unsigned int	value;
	struct {
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	} rgba;
}				t_color;

typedef struct s_fractal
{
	int			type;
	int			iteration_num;
	bool		is_julia_locked;
	bool		is_color_smooth;
	//t_color		smooth_color;
	t_color		color;
	double		zoom;
	double		mouse_x;
	double		mouse_y;
	double		offset_x;
	double		offset_y;
}				t_fractal;

struct		s_viewport
{
	void		*mlx;
	void		*window;
	t_render	render;
	t_image		image;
	t_fractal	fractal;
};

/*---------------------------------FRACTOL------------------------------------*/
int		main(int argc, char **argv);

/*-----------------------------------UTILS------------------------------------*/
void	help_msg(void);
void	error_msg(char *error_text);

/*---------------------------------FRACTALS-----------------------------------*/
int		calc_mandelbrot(t_fractal *fractal, t_complex_number *c);
int		calc_julia(t_fractal *fractal, t_complex_number *c, int x, int y);
int		calc_burning_ship(t_fractal *fractal, t_complex_number *c);
int		calc_nova(t_fractal *fractal, t_complex_number *c, int x, int y);

/*------------------------------FRACTAL_UTILS---------------------------------*/
void	set_fractal_type(t_viewport *viewpoint, char *fractal_type);
void	change_fractal(int key, t_viewport *viewport);
void	calculate_c_real(t_complex_number *c, t_fractal *fractal, int x);
void	calculate_c_im(t_complex_number *c, t_fractal *fractal, int y);

/*---------------------------------VIEWPORT-----------------------------------*/
void	init_viewport(t_viewport *viewport, char *fractal_type);
void	init_fractal(t_viewport *viewpoint, int fractal_type);
int		calc_fractal(t_fractal *fractal, t_complex_number *c, int x, int y);

/*------------------------------VIEWPORT_UTILS--------------------------------*/
void	change_color(t_viewport *viewport, int key);
void	change_view(t_viewport *viewport, int key);
void	change_iter(t_viewport *viewport, int key);

/*----------------------------------EVENTS------------------------------------*/
int		on_key_hook_event(int key, t_viewport *viewport);
int		on_mouse_hook_event(int key, int x, int y,
			t_viewport *viewport);
int		on_mousemove_event(int x, int y, t_viewport *viewport);
int		on_destroy_event(t_viewport *viewport);

/*----------------------------------THREADS-----------------------------------*/
void	thread_manager(t_viewport *viewport);
void	*thread_create(void *viewport);
void	thread_loop(t_thread *thread_data, t_viewport *viewport,
			t_fractal *fractal, t_complex_number c);

/*-----------------------------------COLOR------------------------------------*/
t_color	color_lerp(t_color c1, t_color c2, double p);
t_color	get_linear_color(double i, int max);
t_color	get_smooth_color(t_pixel p, int max);
int		get_color(t_viewport *viewport, t_pixel p);
void	set_pixel_color(t_viewport *viewport, int x, int y,
			int color);

#endif
