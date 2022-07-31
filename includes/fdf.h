/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:40:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 13:28:20 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <string.h>

# define Y_SIZE 1080
# define X_SIZE 1920
# define XC 960
# define YC 540
# define TRUE_ISO 0.523599
# define DIMETRIC_ISO 0.463744
# define SQRT3DIVBY2 0.866

/* structures */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		**matrix;
	int		width;
	int		length;
	void	*mlx;
	void	*win;
}	t_map;

typedef struct s_point
{
	int		x1;
	int		y1;
	int		x0;
	int		y0;
	int		z0;
	int		z1;
	float	shortest;
	int		width;
	int		length;
	float	longest;
	int		n;
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	int		color;
	int		color2;
	int		zoom;
	int		offsetx;
	int		offsety;
	int		offsetz;
	int		t;
	float	a0;
	float	a1;
	float	a2;
	t_img	*img;
	t_map	*data;
}	t_point;

/* This is a minimal set of ANSI/VT100 color codes */
# define END "\033[0m"
# define GREY "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"

/* Key codes */
# define ESC 65307
# define A 97
# define S 115
# define D 100
# define W 119
# define UP 65362
# define DOWN 65364
# define RIGHT 65363
# define LEFT 65361
# define PLUS 65451
# define MINUS 65453
# define INCREASE 61
# define DECREASE 45

/* Exit codes */
# define EXIT_FAILURE 1
# define EXIT_SUCCESS 0

/* Useful protos */
	/* --- graph --- */
void	ft_draw(t_point *points, t_img *img, t_map *data);
int		ft_findzoom(int length, int width);
void	ft_get_z_1(t_map *data, t_point *points, int *x, int *y);
void	ft_get_z_2(t_map *data, t_point *points, int *x, int *y);
void	ft_bresenham(t_point *points, t_img *img);
	/* --- color ---*/
int		ft_lin_grad(t_point *points, int *i);
int		ft_rgb(int r, int g, int b);
void	ft_my_mpp(t_img *img, int x, int y, int color);
	/* --- isometry --- */
void	ft_isometric(t_point *points);
float	ft_theta(int t);
void	ft_zoom(t_point *points, int *tmp_x, int *tmp_y, int decide);
	/* --- Key events --- */
int		ft_closebutton(t_point *param);
int		ft_escape(int key, t_point *param);
void	ft_adjust_offset(int key, t_point *points);
void	ft_adjust_rotation(int key, t_point *points);
void	ft_adjust_zoom(int key, t_point *points);
void	ft_adjust_projection(int key, t_point *points);
void	ft_reset_view(int key, t_point *points);
	/* --- map --- */
int		ft_build_mtx(t_map *map, char *path);
void	ft_build_map(t_map *map, char *path);
int		ft_check_map(char *path, t_map *map);
void	ft_build_color(t_map *map, char *path);
void	ft_free_map(t_map **map);
	/* --- matrix --- */
int		ft_get_matrix_int(t_map *map, int i, int j);
void	ft_set_matrix_int(t_map *map, int i, int j, int val);
int		ft_get_matrix_color(t_map *map, int i, int j);
void	ft_set_matrix_color(t_map *map, int i, int j, int val);
	/* --- bonus --- */
void	ft_rotation_x(t_point *points);
void	ft_rotation_y(t_point *points);
void	ft_rotation_z(t_point *points);

#endif
