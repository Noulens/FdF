/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:35:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/06 19:56:59 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_img	img;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;

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
	mlx_loop(mlx);
}
