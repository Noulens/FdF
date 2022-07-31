/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 12:39:50 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_fdf_file_checker(char *path)
{
	int	i;
	int	fd;

	if (path == NULL)
		return (0);
	i = ft_strlen(path);
	if (i <= 4)
		return (0);
	if (!ft_strnstr(path + i - 4, ".fdf", 4))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}

static void	ft_init(t_img **img, t_map **data, char *path, int argc)
{
	if (argc != 2 || !ft_fdf_file_checker(path))
	{
		ft_printf(RED"Usage : ./fdf <filename.fdf>\n"END);
		exit(EXIT_FAILURE);
	}
	*data = (t_map *)malloc(sizeof(t_map));
	if (!*data)
	{
		ft_printf(RED"malloc issue: ft_init\n"END);
		exit(EXIT_FAILURE);
	}
	if (!ft_check_map(path, *data))
	{
		free(*data);
		ft_printf(RED"incorrect map size\n"END);
		exit(EXIT_FAILURE);
	}
	*img = (t_img *)malloc(sizeof(t_img));
	if (!*img)
	{
		free(*data);
		ft_printf(RED"malloc issue: ft_init\n"END);
		exit(EXIT_FAILURE);
	}
}

void	ft_offset(t_point *points)
{
	points->offsetx = 0;
	points->offsety = 0;
	points->offsetz = 0;
	points->t = 0;
	points->a0 = 0;
	points->a1 = 0;
	points->a2 = 0;
}

int	ft_key(int key, t_point *points)
{
	ft_adjust_offset(key, points);
	ft_adjust_rotation(key, points);
	ft_adjust_zoom(key, points);
	ft_adjust_projection(key, points);
	ft_reset_view(key, points);
	mlx_destroy_image(points->data->mlx, points->img->img);
	points->img->img = mlx_new_image(points->data->mlx, X_SIZE, Y_SIZE);
	points->img->addr = mlx_get_data_addr(points->img->img,
			&points->img->bpp, &points->img->line_length,
			&points->img->endian);
	ft_draw(points, points->img, points->data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_img	*img;
	t_map	*data;
	t_point	points;

	ft_init(&img, &data, argv[1], argc);
	if (!ft_build_mtx(data, argv[1]))
		return (free(data), free(img), 1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_printf("env -i used\n"), ft_free_map(&data), free(img), 0);
	data->win = mlx_new_window(data->mlx, X_SIZE, Y_SIZE, "FDF - TNO");
	img->img = mlx_new_image(data->mlx, X_SIZE, Y_SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	points.zoom = ft_findzoom(data->length, data->width);
	points.img = img;
	points.data = data;
	ft_offset(&points);
	ft_draw(&points, img, data);
	mlx_key_hook(data->win, ft_key, &points);
	mlx_hook(data->win, 17, 1L << 17, ft_closebutton, &points);
	mlx_loop(data->mlx);
	return (0);
}
