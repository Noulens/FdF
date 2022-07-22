/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:40:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/22 14:45:28 by tnoulens         ###   ########.fr       */
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
# define TRUE_ISO 0.523599
# define DIMETRIC_ISO 0.46373398

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
	float	x1;
	float	y1;
	float	x0;
	float	y0;
	float	z0;
	float	z1;
	float	error;
	float	dx;
	float	dy;
	float	sx;
	float	sy;
	int		color;
	int		zoom;
	int		offsetx;
	int		offsety;
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
void	ft_my_mpp(t_img *img, int x, int y, int color);
int		ft_trgb(int t, int r, int g, int b);
int		ft_close(int key, t_map *data);
int		ft_closebutton(void *param, t_map **data);
void	ft_bresenham(t_point *points, t_img *img);
void	ft_draw(t_point *points, t_img *img, t_map *data);
	/* --- isometry --- */
void	ft_isometric(t_point *points);
	/* --- Key events --- */
void	ft_keyhook(int keycode, t_map *data);
	/* --- map --- */
void	ft_build_mtx(t_map *map, char *path);
void	ft_build_map(t_map *map, char *path);
int		ft_check_map(char *path, t_map *map);
int		ft_fdf_file_checker(char *path);
void	ft_build_color(t_map *map, char *path);
void	ft_free_map(t_map **map);
	/* --- matrix --- */
int		ft_get_matrix_int(t_map *map, int i, int j);
void	ft_set_matrix_int(t_map *map, int i, int j, int val);
int		ft_get_matrix_color(t_map *map, int i, int j);
void	ft_set_matrix_color(t_map *map, int i, int j, int val);

#endif
