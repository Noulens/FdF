/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:23:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/18 19:28:34 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_my_mpp(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_closebutton(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int	ft_close(int keycode, t_map *data)
{
	if (keycode == ESC)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

void	ft_free_map(t_map **map)
{
	free((*map)->matrix[0]);
	free((*map)->matrix[1]);
	free((*map)->matrix);
	free((*map)->mlx);
	free((*map)->win);
	free((*map));
}
