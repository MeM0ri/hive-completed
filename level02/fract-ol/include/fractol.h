/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:57:28 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/25 17:18:03 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "ft_printf.h"
# include "libft.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_NAME "fract-ol"

typedef	struct	s_image {
	void	*img_ptr;
	char	*addr_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_image;

typedef	struct s_fractal
{
	int		type;
}				t_fractal;


typedef	struct	s_engine
{
	void		*mlx;
	void		*window;
	t_image		image;
	t_fractal	fractal;
}				t_engine;


/*---------------------------------FRACTOLS-----------------------------------*/
int		main(int argc, char **argv);

/*---------------------------------FRACTALS-----------------------------------*/
void	draw(t_engine *engine);

/*----------------------------------ENGINE------------------------------------*/
void	init_engine(t_engine *engine, char *fractal_type);

/*-----------------------------------UTILS------------------------------------*/


#endif
