/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waxxy <waxxy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:58 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/21 22:15:04 by waxxy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

static int	ft_err(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (-b);
}

void	ft_bresenham(t_point *points, t_img *img)
{
	register float	e2;

	points->dx = fabsf(points->x1 - points->x0);
	points->dy = fabsf(points->y1 - points->y0);
	points->sx = ft_slope(points->x0, points->x1);
	points->sy = ft_slope(points->y0, points->y1);
	points->error = ft_err(points->dx, points->dy) / 2;
	while ((int)(points->x0 - points->x1) || (int)(points->y0 - points->y1))
	{
		//ft_printf("y = %d, x = %d\n", points->y0, points->x0);
		if (points->x0 <= X_SIZE && points->y0 <= Y_SIZE)
			ft_my_mpp(img, points->x0, points->y0, points->color);
		e2 = points->error;
		if (e2 > -points->dx)
		{
			points->error -= points->dy;
			points->x0 += points->sx;
		}
		if (e2 < points->dy)
		{
			points->error += points->dx;
			points->y0 += points->sy;
		}
	}
}

static void	ft_zoom(t_point *points, int *tmp_x, int *tmp_y, int decide)
{
	if (decide == 1)
	{
		points->x0 = *tmp_x * points->zoom;
		points->y0 = *tmp_y * points->zoom;
		points->x1 = (*tmp_x + 1) * points->zoom + 1;
		points->y1 = points->y0;
	}
	else
	{
		points->x0 = *tmp_x * points->zoom;
		points->y0 = *tmp_y * points->zoom;
		points->y1 = (*tmp_y + 1) * points->zoom;
		points->x1 = points->x0;
	}
}

void	ft_draw(t_point *points, t_img *img, t_map *data)
{
	int	tmp_x;
	int	tmp_y;
	int	tmp_z;

	tmp_y = 0;
	while (tmp_y < data->length)
	{
		tmp_x = 0;
		while (tmp_x < data->width)
		{
			points->color = ft_get_matrix_color(data, tmp_y, tmp_x);
			ft_zoom(points, &tmp_x, &tmp_y, 1);
			//ft_printf("bres 1\n");
			if (tmp_x != data->width - 1)
				ft_bresenham(points, img);
			ft_zoom(points, &tmp_x, &tmp_y, 0);
			//ft_printf("bres 2\n");
			if (tmp_y != data->length - 1)
				ft_bresenham(points, img);
			tmp_x++;
		}
		tmp_y++;
	}
	//ft_printf("x = %d, y = %d\n", tmp_x, tmp_y);
}
