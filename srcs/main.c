/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/20 16:38:29 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		ft_printf(RED"malloc issue: ft_init"END);
		exit(EXIT_FAILURE);
	}
	if (!ft_check_map(path, *data))
	{
		free(*data);
		ft_printf(RED"incorrect map size"END);
		exit(EXIT_FAILURE);
	}
	*img = (t_img *)malloc(sizeof(t_img));
	if (!*img)
	{
		free(*data);
		ft_printf(RED"malloc issue: ft_init"END);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_img	*img;
	t_map	*data;
	t_point	points;

	ft_init(&img, &data, argv[1], argc);
	ft_build_mtx(data, argv[1]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, X_SIZE, Y_SIZE, "Hell world");
	img->img = mlx_new_image(data->mlx, X_SIZE, Y_SIZE);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	points.zoom = 2;
	ft_draw(&points, img, data);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, ft_close, &data->win);
	mlx_hook(data->win, 17, 1L << 17, ft_closebutton, &data->win);
	//mlx_key_hook(data->win, ft_keyhook, &data);
	mlx_loop(data->mlx);
	ft_free_map(&data);
	return (0);
}
