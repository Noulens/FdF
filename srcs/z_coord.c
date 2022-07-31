/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_coord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:48:12 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 12:12:30 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_get_colored(t_point *points)
{
	int	n;

	n = points->zoom >> 1;
	if (points->z0 == 0)
		points->color = 0xecc6c6;
	else if (abs(points->z0) > 0 && abs(points->z0) <= 10 * n)
		points->color = 0xcc0000;
	else if (abs(points->z0) > 10 * n && abs(points->z0) <= 15 * n)
		points->color = 0x9966ff;
	else
		points->color = 0x00ff00;
	if (points->z1 == 0)
		points->color2 = 0xecc6c6;
	else if (abs(points->z1) > 0 && abs(points->z1) <= 10 * n)
		points->color2 = 0xcc0000;
	else if (abs(points->z1) > 10 * n && abs(points->z1) <= 15 * n)
		points->color2 = 0x9966ff;
	else
		points->color2 = 0x00ff00;
}

void	ft_get_z_1(t_map *data, t_point *points, int *x, int *y)
{
	points->color = ft_get_matrix_color(data, *y, *x);
	points->z0 = ft_get_matrix_int(data, *y, *x) * (points->zoom >> 1);
	if (points->z0 != 0)
		points->z0 = points->z0 + points->z0 * points->offsetz;
	if (*x < data->width - 1)
		points->z1 = ft_get_matrix_int(data, *y, *x + 1) * (points->zoom >> 1);
	if (points->z1 != 0)
		points->z1 = points->z1 + points->z1 * points->offsetz;
	if (!points->color)
		ft_get_colored(points);
	else if (*x < data->width - 1)
		points->color2 = ft_get_matrix_color(data, *y, *x + 1);
	else
		points->color2 = 0xecc6c6;
}

void	ft_get_z_2(t_map *data, t_point *points, int *x, int *y)
{
	points->color = ft_get_matrix_color(data, *y, *x);
	points->z0 = ft_get_matrix_int(data, *y, *x) * (points->zoom >> 1);
	if (points->z0 != 0)
		points->z0 = points->z0 + points->z0 * points->offsetz;
	if (*y < data->length - 1)
		points->z1 = ft_get_matrix_int(data, *y + 1, *x) * (points->zoom >> 1);
	if (points->z1 != 0)
		points->z1 = points->z1 + points->z1 * points->offsetz;
	if (!points->color)
		ft_get_colored(points);
	else if (*y < data->length - 1)
		points->color2 = ft_get_matrix_color(data, *y + 1, *x);
	else
		points->color2 = 0xecc6c6;
}
