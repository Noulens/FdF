/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/12 12:10:14 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_img	img;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_map	*mapptr;

	if (argc != 2)
		return (ft_printf(RED"Usage : ./fdf <filename.fdf>\n"END), -1);
	mapptr = (t_map *)malloc(sizeof(t_map));
	if (!mapptr)
		return (ft_printf(RED"malloc issue: main"END), -1);
	mapptr->width = 0;
	mapptr->length = 0;
	if (!ft_check_map(argv[1], mapptr))
		return (free(mapptr), ft_printf(RED"incorrect map size"END), -1);
	ft_build_mtx(mapptr, argv[1]);
	x = 0;
	while (x < mapptr->width)
	{
		y = 0;
		while (y < mapptr->length)
		{
			ft_printf(" %d ", ft_get_matrix_color(mapptr, x, y));
			++y;
		}
		++x;
		ft_putchar_fd('\n', 0);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hell world");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	x = 0;
	while (x < mapptr->width)
	{
		y = 0;
		while (y < mapptr->length)
		{
			ft_my_mpp(&img, x + 100, y + 100, ft_get_matrix_color(mapptr, x, y));
			y = y + 1;
		}
		x = x + 1;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, 2, 1L << 0, ft_close, &mlx_win);
	mlx_loop(mlx);
	ft_free_map(&mapptr);
	return (0);
}
