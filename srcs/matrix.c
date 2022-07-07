/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:20:11 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/07 18:30:37 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_get_matrix_int(t_map *map, int i, int j)
{
	return (map->matrix[0][i + i * (map->width - 1) + j]);
}

void	ft_set_matrix_int(t_map *map, int i, int j, int val)
{
	map->matrix[0][i + i * (map->width - 1) + j] = val;
}

int	ft_get_matrix_color(t_map *map, int i, int j)
{
	return (map->matrix[1][i + i * (map->width - 1) + j]);
}

void	ft_set_matrix_color(t_map *map, int i, int j, int val)
{
	map->matrix[1][i + i * (map->width - 1) + j] = val;
}
