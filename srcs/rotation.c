/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:00:06 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 12:30:53 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_rotation_x(t_point *points)
{
	int	dy;
	int	dz;

	dy = points->y0;
	dz = points->z0;
	points->y0 = dy * cos(points->a0) + dz * sin(points->a0);
	points->z0 = -dy * sin(points->a0) + dz * cos(points->a0);
	dy = points->y1;
	dz = points->z1;
	points->y1 = dy * cos(points->a0) + dz * sin(points->a0);
	points->z1 = -dy * sin(points->a0) + dz * cos(points->a0);
}

void	ft_rotation_y(t_point *points)
{
	int	dx;
	int	dz;

	dx = points->x0;
	dz = points->z0;
	points->x0 = dx * cos(points->a1) + dz * sin(points->a1);
	points->z0 = -dx * sin(points->a1) + dz * cos(points->a1);
	dx = points->x1;
	dz = points->z1;
	points->x1 = dx * cos(points->a1) + dz * sin(points->a1);
	points->z1 = -dx * sin(points->a1) + dz * cos(points->a1);
}

void	ft_rotation_z(t_point *points)
{
	int	dx;
	int	dy;

	dx = points->x0;
	dy = points->y0;
	points->x0 = dx * cos(points->a2) - dy * sin(points->a2);
	points->y0 = dx * sin(points->a2) + dy * cos(points->a2);
	dx = points->x1;
	dy = points->y1;
	points->x1 = dx * cos(points->a2) - dy * sin(points->a2);
	points->y1 = dx * sin(points->a2) + dy * cos(points->a2);
}

void	ft_adjust_rotation(int key, t_point *points)
{
	if (key == W)
		points->a0 += 0.09;
	if (key == A)
		points->a1 -= 0.09;
	if (key == S)
		points->a0 -= 0.09;
	if (key == D)
		points->a1 += 0.09;
	if (key == PLUS)
		points->a2 += 0.09;
	if (key == MINUS)
		points->a2 -= 0.09;
}

void	ft_reset_view(int key, t_point *points)
{
	if (key == 114)
	{
		points->a0 = 0;
		points->a1 = 0;
		points->a2 = 0;
		points->offsetx = 0;
		points->offsety = 0;
		points->offsetz = 0;
	}
}
