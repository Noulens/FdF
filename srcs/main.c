/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/18 14:11:44 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_img	img;
	t_map	*mapptr;

	if (argc != 2)
		return (ft_printf(RED"Usage : ./fdf <filename.fdf>\n"END), -1);
	mapptr = (t_map *)malloc(sizeof(t_map));
	if (!mapptr)
		return (ft_printf(RED"malloc issue: main"END), -1);
	if (!ft_check_map(argv[1], mapptr))
		return (free(mapptr), ft_printf(RED"incorrect map size"END), -1);
	ft_build_mtx(mapptr, argv[1]);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hell world");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
			&img.endian);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L << 0, ft_close, &img.win);
	mlx_loop(img.mlx);
	ft_free_map(&mapptr);
	return (0);
}
