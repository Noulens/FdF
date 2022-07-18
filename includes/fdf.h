/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:40:17 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/18 14:12:18 by tnoulens         ###   ########.fr       */
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

/* structures */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
}	t_img;

typedef struct s_map
{
	int	**matrix;
	int	width;
	int	length;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
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
int		ft_close(int key, t_img *img);
int		ft_closebutton(int buttoncode, t_img *img);
	/* --- map --- */
void	ft_build_mtx(t_map *map, char *path);
void	ft_build_map(t_map *map, char *path);
int		ft_check_map(char *path, t_map *map);
void	ft_build_color(t_map *map, char *path);
void	ft_free_map(t_map **map);
	/* --- matrix --- */
int		ft_get_matrix_int(t_map *map, int i, int j);
void	ft_set_matrix_int(t_map *map, int i, int j, int val);
int		ft_get_matrix_color(t_map *map, int i, int j);
void	ft_set_matrix_color(t_map *map, int i, int j, int val);

#endif
