/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 13:24:19 by tnoulens          #+#    #+#             */
/*   Updated: 2022/07/31 12:39:14 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ft_count_word(const char *str, char c)
{
	int		word_flag;
	int		i;
	int		word_count;

	i = 0;
	word_flag = 0;
	word_count = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\n')
		{
			word_flag = 0;
			++i;
		}
		else if (word_flag == 1)
			++i;
		else
		{
			word_flag = 1;
			++word_count;
			++i;
		}
	}
	return (word_count);
}

int	ft_check_map(char *path, t_map *map)
{
	int		fd;
	int		tmp;
	char	*ptr;

	map->length = 0;
	map->width = 0;
	fd = open(path, O_RDONLY);
	ptr = get_next_line(fd);
	if (!ptr || ptr[0] == '\n')
		return (close(fd), free(ptr), 0);
	while (ptr)
	{
		if (ptr[0] == '\n')
			return (close(fd), free(ptr), 1);
		tmp = map->width;
		map->length++;
		map->width = ft_count_word(ptr, ' ');
		if ((tmp != 0 && tmp != map->width) || map->width == 0)
			return (close(fd), free(ptr), 0);
		free(ptr);
		ptr = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	ft_build_map(t_map *map, char *path)
{
	char	*p;
	char	**ptr;
	int		fd;
	int		i;
	int		j;

	fd = open(path, O_RDONLY);
	p = get_next_line(fd);
	i = 0;
	while (p)
	{
		ptr = ft_split(p, ' ');
		j = 0;
		while (ptr[j] && *ptr[j] != '\n')
			map->matrix[0][i++] = ft_atoi(ptr[j++]);
		ft_free_split(ptr);
		free (p);
		p = get_next_line(fd);
		if (p && p[0] == '\n')
			return (close(fd), free (p), (void)0);
	}
	close(fd);
}

void	ft_build_color(t_map *map, char *path)
{
	char	*p;
	char	**ptr;
	int		fd;
	int		i;
	int		j;

	fd = open(path, O_RDONLY);
	p = get_next_line(fd);
	i = 0;
	while (p)
	{
		ptr = ft_split(p, ' ');
		j = 0;
		while (ptr[j] && *ptr[j] != '\n')
			map->matrix[1][i++] = ft_atoi_base(ft_strchr(ptr[j++], ','), 16);
		ft_free_split(ptr);
		free (p);
		p = get_next_line(fd);
		if (p && p[0] == '\n')
			return (close(fd), free (p), (void)0);
	}
	close(fd);
}

int	ft_build_mtx(t_map *map, char *path)
{
	map->matrix = (int **)malloc(3 * sizeof(int *));
	if (!map->matrix)
		return (ft_printf("malloc error: ft_build_mtx\n"), 0);
	map->matrix[0] = (int *)ft_calloc(map->length * map->width, sizeof(int));
	if (!map->matrix[0])
	{
		free(map->matrix[0]);
		free(map->matrix);
		ft_printf("malloc error: ft_build_mtx\n");
		exit(EXIT_FAILURE);
	}
	map->matrix[1] = (int *)ft_calloc(map->length * map->width, sizeof(int));
	if (!map->matrix[1])
	{
		free(map->matrix[1]);
		free(map->matrix);
		ft_printf("malloc error: ft_build_mtx\n");
		exit(EXIT_FAILURE);
	}
	map->matrix[2] = NULL;
	ft_build_map(map, path);
	ft_build_color(map, path);
	return (1);
}
