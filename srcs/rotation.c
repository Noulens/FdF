/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:00:06 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/29 14:19:17 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotation_x(t_point *points)
{
	points->y0 = points->y0 * cos(points->a0) + points->z0 * sin(points->a0);
	points->z0 = -points->y0 * sin(points->a0) + points->z0 * cos(points->a0);
	points->y1 = points->y1 * cos(points->a0) + points->z1 * sin(points->a0);
	points->z1 = -points->y1 * sin(points->a0) + points->z1 * cos(points->a0);
}

void	ft_rotation_y(t_point *points)
{
	points->x0 = points->x0 * cos(points->a1) + points->z0 * sin(points->a1);
	points->z0 = -points->x0 * sin(points->a1) + points->z0 * cos(points->a1);
	points->x1 = points->x1 * cos(points->a1) + points->z1 * sin(points->a1);
	points->z1 = -points->x1 * sin(points->a1) + points->z1 * cos(points->a1);
}

void	ft_rotation_z(t_point *points)
{
	points->x0 = points->x0 * cos(points->a2) - points->y0 * sin(points->a2);
	points->y0 = -points->x0 * sin(points->a2) + points->y0 * cos(points->a2);
	points->x1 = points->x1 * cos(points->a2) - points->y1 * sin(points->a2);
	points->y1 = -points->x1 * sin(points->a2) + points->y1 * cos(points->a2);
}
