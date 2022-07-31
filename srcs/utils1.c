/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:23:49 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 13:28:01 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_my_mpp(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ft_escape(int key, t_point *param)
{
	if (key == 65307)
	{
		mlx_destroy_image(param->data->mlx, param->img->img);
		mlx_destroy_window(param->data->mlx, param->data->win);
		mlx_destroy_display(param->data->mlx);
		ft_free_map(&param->data);
		free(param->img);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_closebutton(t_point *param)
{
	mlx_destroy_image(param->data->mlx, param->img->img);
	mlx_destroy_window(param->data->mlx, param->data->win);
	mlx_destroy_display(param->data->mlx);
	ft_free_map(&param->data);
	free(param->img);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_map(t_map **map)
{
	free((*map)->matrix[0]);
	free((*map)->matrix[1]);
	free((*map)->matrix);
	if ((*map)->mlx)
		free((*map)->mlx);
	free((*map));
}
