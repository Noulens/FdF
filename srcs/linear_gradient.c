/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:45:27 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/27 17:06:03 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int get_r(int rgb)
{
	return ((rgb >> 16) & 0xff);
}

static int get_g(int rgb)
{
	return ((rgb >> 8) & 0xff);
}

static int get_b(int rgb)
{
	return (rgb & 0xff);
}

static int	ft_gradient(t_point	*points, int *i)
{
	register int	r;
	register int	g;
	register int	b;
	float			coeff1;
	float			coeff2;

	coeff1 = (points->longest - *i) / points->longest;
	coeff2 = (*i / points->longest);
	r = get_r(points->color) * coeff1 + coeff2 * get_r(points->color2);
	g = get_g(points->color) * coeff1 + coeff2 * get_g(points->color2);
	b = get_b(points->color) * coeff1 + coeff2 * get_b(points->color2);
	return (ft_rgb(r, g, b));
}

int	ft_linear_gradient(t_point *points, int *i)
{
	if (points->z0 == 0 && points->z1 == 0 && points->color == 0)
		return (0xffffff);
	else if (points->z0 && points->z1 && points->z0 == points->z1
		&& points->color == 0)
		return (0xcc0000);
	else if (points->z0 < points->z1
		&& points->color == 0)
		return (points->color = ft_gradient(points, i), points->color);
	else if (points->z0 > points->z1
		&& points->color == 0)
		return(points->color = ft_gradient(points, i), points->color);
	else
		return (points->color);
}

/*
	if (points->z0 == 0 && points->z1 == 0 && points->color == 0)
		points->color = 0xffffff;
	else if (points->z0 && points->z1 && points->z0 == points->z1
		&& points->color == 0)
		points->color = 0xcc0000;
	else if (points->z0 < points->z1
		&& points->color == 0)
		points->color = ft_gradient();
	else if (points->z0 > points->z1
		&& points->color == 0)
		points->color = ft_gradient();
*/
