/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/07 18:27:50 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
//	t_img	img;
//	void	*mlx;
//	void	*mlx_win;
	int		x;
	int		y;
	t_map	*mapptr;

	if (argc != 2)
		return (ft_printf(RED"Usage : ./fdf_linux <filename.fdf>\n"END), -1);
	mapptr = (t_map *)malloc(sizeof(t_map));
	if (!mapptr)
		return (ft_printf(RED"malloc issue: main"END), -1);
	mapptr->width = 0;
	mapptr->length = 0;
	if (!ft_check_map(argv[1], mapptr))
		return (free(mapptr), -1);
	ft_build_mtx(mapptr);
	x = 0;
	while (x < mapptr->width)
	{
		y = 0;
		while (y < mapptr->length)
		{
			ft_printf(" %d ", ft_get_matrix_int(mapptr, x, y));
			++y;
		}
		++x;
		ft_putchar_fd('\n', 0);
	}
	/*
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hell world");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	x = 1920 / 2 - 125;
	while (x < 1920 / 2 + 125)
	{
		y = 1080 / 2 - 125;
		while (y < 1080 / 2 + 125)
		{
			ft_my_mpp(&img, x, y, 0x00823C46);
			y = y + 1;
		}
		x = x + 1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L << 0, ft_close, &mlx_win);
	mlx_loop(mlx);*/
	return (0);
}
