/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:48:12 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/27 16:49:20 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_z_1(t_map *data, t_point *points, int *x, int *y)
{
	points->color = ft_get_matrix_color(data, *y, *x);

	if (*x < data->width - 1)
		points->color2 = ft_get_matrix_color(data, *y, *x + 1);
	else
		points->color2 = 0xffffff;
		
	points->z0 = ft_get_matrix_int(data, *y, *x) * (points->zoom >> 1)
		+ points->offsetz;
	if (*x < data->width - 1)
		points->z1 = ft_get_matrix_int(data, *y, *x + 1) * (points->zoom >> 1)
			+ points->offsetz;
}

void	ft_get_z_2(t_map *data, t_point *points, int *x, int *y)
{
	points->color = ft_get_matrix_color(data, *y, *x);

	if (*y < data->length - 1)
		points->color2 = ft_get_matrix_color(data, *y + 1, *x);
	else
		points->color2 = 0xffffff;
		
	points->z0 = ft_get_matrix_int(data, *y, *x) * (points->zoom >> 1)
		+ points->offsetz;
	if (*y < data->length - 1)
		points->z1 = ft_get_matrix_int(data, *y + 1, *x) * (points->zoom >> 1)
			+ points->offsetz;
}
