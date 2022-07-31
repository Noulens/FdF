/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:08:25 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 12:35:27 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_findzoom(int length, int width)
{
	int	zoomx;
	int	zoomy;
	int	zoommin;

	zoommin = 1;
	zoomx = X_SIZE / width;
	zoomy = Y_SIZE / length;
	if (zoomy < zoomx && zoomy < 60)
		return (zoomy);
	else if (zoomy >= zoomx && zoomx < 60)
		return (zoomx);
	else if (zoomy < 1 || zoomx < 1)
		return (zoommin);
	else
		return (60);
}

void	ft_adjust_zoom(int key, t_point *points)
{
	if (key == INCREASE)
		points->zoom += 1;
	if (key == DECREASE)
	{
		if (points->zoom != 1)
			points->zoom -= 1;
	}
}

void	ft_adjust_projection(int key, t_point *points)
{
	if (key == 112)
		points->t += 1;
}

void	ft_zoom(t_point *points, int *tmp_x, int *tmp_y, int decide)
{
	points->x0 = *tmp_x * points->zoom + points->offsetx;
	points->y0 = *tmp_y * points->zoom + points->offsety;
	if (decide == 1)
	{
		points->x1 = ((*tmp_x + 1) * points->zoom) + points->offsetx;
		points->y1 = points->y0;
		ft_rotation_z(points);
		ft_rotation_x(points);
		ft_rotation_y(points);
		ft_isometric(points);
	}
	else
	{
		points->y1 = ((*tmp_y + 1) * points->zoom) + points->offsety;
		points->x1 = points->x0;
		ft_rotation_z(points);
		ft_rotation_x(points);
		ft_rotation_y(points);
		ft_isometric(points);
	}
}

void	ft_isometric(t_point *points)
{
	int	px;
	int	py;
	int	px1;
	int	py1;

	px = points->x0;
	py = points->y0;
	px1 = points->x1;
	py1 = points->y1;
	points->x0 = (px - py) * cos(ft_theta(points->t)) - (((points->width / 2
					- points->length / 2) * points->zoom)
			* cos(ft_theta(points->t))) + XC;
	points->y0 = (px + py) * sin(ft_theta(points->t)) - points->z0
		- ((points->zoom * (points->width + points->length + 1))
			* sin(ft_theta(points->t)) - points->zoom) + Y_SIZE;
	points->x1 = (px1 - py1) * cos(ft_theta(points->t)) - (((points->width / 2
					- points->length / 2) * points->zoom)
			* cos(ft_theta(points->t))) + XC;
	points->y1 = (px1 + py1) * sin(ft_theta(points->t)) - points->z1
		- ((points->zoom * (points->width + points->length + 1))
			* sin(ft_theta(points->t)) - points->zoom) + Y_SIZE;
}
