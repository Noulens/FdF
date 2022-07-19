/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:58 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/19 12:03:46 by tnoulens         ###   ########.fr       */
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

void	ft_non_naive_bresenham(t_point *points, t_img *img, t_map *data)
{
	register int	e2;

	points->dx = abs(points->x1 - points->x0);
	points->dy = abs(points->y1 - points->y0);
	points->sx = ft_slope(points->x0, points->x1);
	points->sy = ft_slope(points->y0, points->y1);
	points->error = ft_err(points->dx, points->dy) / 2;
	while (1)
	{
		ft_my_mpp(img, points->x0, points->y0, ft_get_matrix_color(data, points->y0, points->x0));
		if (points->x0 == points->x1 && points->y0 == points->y1)
			break ;
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

void	ft_draw(t_point *points, t_img *img, t_map *data)
{
	points->y0 = 0;
	while (points->y0 <= data->length)
	{
		points->x0 = 0;
		while (points->x0 < data->width)
		{
			points->x1 = (points->x0 + 1);
			points->y1 = points->y0;
			ft_non_naive_bresenham(points, img, data);
			points->x0++;
		}
		points->y1 = (points->y0 + 1);
		points->x1 = points->x0;
		ft_non_naive_bresenham(points, img, data);
		points->y0++;
	}
}
