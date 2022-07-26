/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:45:27 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/26 16:43:51 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int get_r(int trgb)
{
	return ((trgb >> 16) & 0xff);
}

int get_g(int trgb)
{
	return ((trgb >> 8) & 0xff);
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	ft_gradient(t_point	*points, int *i)
{
	int	r;
	int	g;
	int	b;

	r = (*i / points->longest) * 
}

int	ft_linear_gradient(t_point *points, int *i)
{
	if (points->z0 == 0 && points->z1 == 0 && points->color1 == 0)
		points->color1 = 0xffffff;
	else if (points->z0 && points->z1 && points->z0 == points->z1
		&& points->color1 == 0)
		points->color1 = 0xcc0000;
	else if (points->z0 < points->z1
		&& points->color1 == 0)
		points->color1 = ft_gradient();
	else if (points->z0 > points->z1
		&& points->color1 == 0)
		points->color1 = ft_gradient();
}

/*
	if (points->z0 == 0 && points->z1 == 0 && points->color1 == 0)
		points->color1 = 0xffffff;
	else if (points->z0 && points->z1 && points->z0 == points->z1
		&& points->color1 == 0)
		points->color1 = 0xcc0000;
	else if (points->z0 < points->z1
		&& points->color1 == 0)
		points->color1 = ft_gradient();
	else if (points->z0 > points->z1
		&& points->color1 == 0)
		points->color1 = ft_gradient();
*/
