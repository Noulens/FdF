/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/18 19:39:35 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_img	*img;
	t_map	*data;
	t_point	points;

	if (argc != 2)
		return (ft_printf(RED"Usage : ./fdf <filename.fdf>\n"END), -1);
	data = (t_map *)malloc(sizeof(t_map));
	if (!data)
		return (ft_printf(RED"malloc issue: main"END), -1);
	img = (t_img *)malloc(sizeof(t_img *));
	if (!img)
		return (free(data), ft_printf(RED"malloc issue: main"END), -1);
	if (!ft_check_map(argv[1], data))
		return (free(data), ft_printf(RED"incorrect map size"END), -1);
	ft_build_mtx(data, argv[1]);

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Hell world");
	img->img = mlx_new_image(data->mlx, 1920, 1080);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	ft_draw(&points, img, data);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	mlx_hook(data->win, 2, 1L << 0, ft_close, &data->win);
	//mlx_key_hook(data->win, ft_keyhook, &data);
	mlx_loop(data->mlx);
	ft_free_map(&data);
	return (0);
}
