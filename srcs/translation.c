/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 10:41:41 by waxxy             #+#    #+#             */
/*   Updated: 2022/07/31 12:35:47 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_adjust_offset(int key, t_point *points)
{
	if (key == 117)
		points->offsetz -= 1;
	if (key == 105)
		points->offsetz += 1;
	if (key == UP)
	{
		points->offsety -= 10;
		points->offsetx -= 10;
	}
	if (key == RIGHT)
	{
		points->offsety -= 10;
		points->offsetx += 10;
	}
	if (key == LEFT)
	{
		points->offsety += 10;
		points->offsetx -= 10;
	}
	if (key == DOWN)
	{
		points->offsety += 10;
		points->offsetx += 10;
	}
}

float	ft_theta(int t)
{
	if (!(t % 2))
		return (TRUE_ISO);
	else
		return (DIMETRIC_ISO);
}
