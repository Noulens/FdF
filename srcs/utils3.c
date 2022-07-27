/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:48:12 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/27 14:37:40 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_z_1(t_map *data, t_point *points, int *x, int *y)
{
	points->z0 = ft_get_matrix_int(data, *y, *x) * (points->zoom >> 1)
		+ points->offsetz;
	if (*x < data->width - 1)
		points->z1 = ft_get_matrix_int(data, *y, *x + 1) * (points->zoom >> 1)
			+ points->offsetz;
}

void	ft_get_z_2(t_map *data, t_point *points, int *x, int *y)
{
	points->z0 = ft_get_matrix_int(data, *y, *x) * (points->zoom >> 1)
		+ points->offsetz;
	if (*y < data->length - 1)
		points->z1 = ft_get_matrix_int(data, *y + 1, *x) * (points->zoom >> 1)
			+ points->offsetz;
}
