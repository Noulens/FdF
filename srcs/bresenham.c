/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:50:58 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/27 17:05:07 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_slope(t_point *points, int *dx2)
{
	if (points->sx < 0)
		points->dx = -1;
	else if (points->sx > 0)
		points->dx = 1;
	if (points->sy < 0)
		points->dy = -1;
	else if (points->sy > 0)
		points->dy = 1;
	if (points->sx < 0)
		*dx2 = -1;
	else if (points->sx > 0)
		*dx2 = 1;
}

static void	ft_compare(t_point *points, int *dx2, int *dy2)
{
	if (!(points->longest > points->shortest))
	{
		points->longest = fabsf(points->sy);
		points->shortest = fabsf(points->sx);
		if (points->sy < 0)
			*dy2 = -1;
		else if (points->sy > 0)
			*dy2 = 1;
		*dx2 = 0;
	}
	points->n = points->longest / 2;
}

static void	ft_init_line(t_point *points, int *dx2, int *dy2)
{
	*dx2 = 0;
	*dy2 = 0;
	points->sx = points->x1 - points->x0;
	points->sy = points->y1 - points->y0;
	ft_slope(points, dx2);
	points->longest = fabsf(points->sx);
	points->shortest = fabsf(points->sy);
	ft_compare(points, dx2, dy2);
}

void	ft_bresenham(t_point *points, t_img *img)
{
	int		i;
	int		dx2;
	int		dy2;

	ft_init_line(points, &dx2, &dy2);
	i = 0;
	while (i <= points->longest)
	{
		if (points->x0 <= X_SIZE && points->y0 <= Y_SIZE
			&& points->x0 >= 0 && points->y0 >= 0)
			ft_my_mpp(img, (int)points->x0, (int)points->y0,
				ft_linear_gradient(points, &i));
		points->n += points->shortest;
		if (!(points->n < points->longest))
		{
			points->n -= points->longest;
			points->x0 += points->dx;
			points->y0 += points->dy;
		}
		else
		{
			points->x0 += dx2;
			points->y0 += dy2;
		}
		++i;
	}
}

void	ft_draw(t_point *points, t_img *img, t_map *data)
{
	int	tmp_x;
	int	tmp_y;

	points->width = data->width;
	points->length = data->length;
	tmp_y = -1;
	while (++tmp_y < data->length)
	{
		tmp_x = -1;
		while (++tmp_x < data->width)
		{
			//points->color = ft_get_matrix_color(data, tmp_y, tmp_x);
			ft_get_z_1(data, points, &tmp_x, &tmp_y);
			ft_zoom(points, &tmp_x, &tmp_y, 1);
			if (tmp_x != data->width - 1)
				ft_bresenham(points, img);
			//points->color = ft_get_matrix_color(data, tmp_y, tmp_x);
			ft_get_z_2(data, points, &tmp_x, &tmp_y);
			ft_zoom(points, &tmp_x, &tmp_y, 0);
			if (tmp_y != data->length - 1)
				ft_bresenham(points, img);
		}
	}
}
