/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:24:19 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/07 18:29:30 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_splitlen(char **p)
{
	int	i;

	i = 0;
	if (!p || !*p)
		return (0);
	while (p[i] && p[i][0] != '\n')
		++i;
	return (i);
}

int	ft_check_map(char *path, t_map *map)
{
	int		fd;
	int		tmp;
	char	*ptr;
	char	**p;

	fd = open(path, O_RDONLY);
	ptr = get_next_line(fd);
	while (ptr)
	{
		tmp = map->width;
		map->length++;
		p = ft_split(ptr, ' ');
		map->width = ft_splitlen(p);
		if ((tmp != 0 && tmp != map->width) || map->width == 0)
			return (ft_free_split(p), free(ptr), 0);
		free(ptr);
		ptr = get_next_line(fd);
		ft_free_split(p);
	}
	close(fd);
	if (map->length != map->width)
		return (0);
	return (1);
}

t_map	*ft_build_mtx(t_map *map)
{
	map->matrix = (int **)malloc(2 * sizeof(int *));
	if (!map->matrix)
		return (NULL);
	map->matrix[0] = (int *)ft_calloc(map->length * map->width, sizeof(int));
	map->matrix[1] = (int *)ft_calloc(map->length * map->width, sizeof(int));
	if (!map->matrix[0] || !map->matrix[1])
		return (free(map->matrix), NULL);
}

void	ft_build_map(t_map *map, char *path)
{
	;
}
