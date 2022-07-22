/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:08:25 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/22 20:03:51 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*void	ft_keyhook(int keycode, t_map *data)
{
	
}*/

void	ft_findoffset(t_map *data, t_point *points)
{
	points->offsetx = (((X_SIZE / 2 - (data->width * points->zoom) / 2) - (Y_SIZE / 2 - (data->length * points->zoom) / 2)) * cos(TRUE_ISO));
	points->offsety = (((X_SIZE / 2 - (data->width * points->zoom) / 2) + (Y_SIZE / 2 - (data->length * points->zoom) / 2)) * sin(TRUE_ISO));
}

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

void	ft_isometric(t_point *points)
{
	points->x0 = (points->x0 - points->y0) * cos(TRUE_ISO);
	points->y0 = (points->x0 + points->y0) * sin(TRUE_ISO) - points->z0;
	points->x1 = (points->x1 - points->y1) * cos(TRUE_ISO);
	points->y1 = (points->x1 + points->y1) * sin(TRUE_ISO) - points->z1;
}

int	ft_fdf_file_checker(char *path)
{
	int	i;
	int	fd;

	if (path == NULL)
		return (0);
	i = ft_strlen(path);
	if (i <= 4)
		return (0);
	if (!ft_strnstr(path + i - 4, ".fdf", 4))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}
