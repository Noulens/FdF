/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:58 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/22 20:06:13 by tnoulens         ###   ########.fr       */
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
		//ft_printf("x0 = %d, y0 = %d, x1 = %d, y1 = %d\n", points->x0, points->y0, points->x1, points->y1);
		if (points->x0 <= X_SIZE && points->y0 <= Y_SIZE
			&& points->x0 >= 0 && points->y0 >= 0)
			ft_my_mpp(img, (int)points->x0, (int)points->y0, points->color);
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
	points->x0 = *tmp_x * points->zoom;
	points->y0 = *tmp_y * points->zoom;
	if (decide == 1)
	{
		points->x1 = ((*tmp_x + 1) * points->zoom + 1);
		points->y1 = points->y0;
		ft_isometric(points);
	}
	else
	{
		points->y1 = ((*tmp_y + 1) * points->zoom + 1);
		points->x1 = points->x0;
		ft_isometric(points);
	}
}

void	ft_draw(t_point *points, t_img *img, t_map *data)
{
	int	tmp_x;
	int	tmp_y;

	tmp_y = -1;
	while (++tmp_y < data->length)
	{
		tmp_x = -1;
		while (++tmp_x < data->width)
		{
			points->color = ft_get_matrix_color(data, tmp_y, tmp_x);
			points->z0 = ft_get_matrix_int(data, tmp_y, tmp_x);
			if (tmp_x < data->width - 1 && tmp_y < data->length - 1)
				points->z1 = ft_get_matrix_int(data, tmp_y, tmp_x + 1);
			ft_zoom(points, &tmp_x, &tmp_y, 1);
			if (tmp_x != data->width - 1)
				ft_bresenham(points, img);
			points->z0 = ft_get_matrix_int(data, tmp_y, tmp_x);
			if (tmp_x < data->width - 1 && tmp_y < data->length - 1)
				points->z1 = ft_get_matrix_int(data, tmp_y + 1, tmp_x);
			ft_zoom(points, &tmp_x, &tmp_y, 0);
			if (tmp_y != data->length - 1)
				ft_bresenham(points, img);
		}
	}
}
