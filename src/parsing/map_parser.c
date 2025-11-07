/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:30:11 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/07 04:29:09 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	is_chars_valid(t_map *map, t_header *header)
{
	int	i;
	int	j;
	int	p_count;

	p_count = 0;
	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (!(map->raw_map[i][j] == '0' || map->raw_map[i][j] == '1'
					|| map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
					|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W'
					|| map->raw_map[i][j] == ' '))
				error_exit_all("Invalid Chars in MAP!", header, map);
			else if (map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
				|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W')
				p_count++;
		}
	}
	if (p_count > 1)
		error_exit_all("Multiple player spawns", header, map);
	else if (p_count == 0)
		error_exit_all("There is no Player", header, map);
}

static void	is_empty_line(t_map *map, t_header *header)
{
	int	i;
	int	flag;
	int	len;
	int	j;

	i = -1;
	while (map->raw_map[++i])
	{
		len = ft_strlen(map->raw_map[i]);
		if (len == 0)
			error_exit_all("There is an empty line in the MAP!", header, map);
		j = -1;
		flag = 1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] != ' ')
				flag = 0;
		}
		if (flag == 1)
			error_exit_all("There is an empty line in the MAP!", header, map);
	}
}

static void	fill_grid(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->raw_map[y])
	{
		x = 0;
		while (map->raw_map[y][x])
		{
			map->grid[y + 1][x + 1] = map->raw_map[y][x];
			x++;
		}
		y++;
	}
	map->grid[y + 2] = NULL;
}

static void	make_grid(t_map *map, t_header *header)
{
	int	y;
	int	column;
	int	max_x;
	int	len;

	y = -1;
	max_x = 0;
	column = 0;
	while (map->raw_map[column])
	{
		len = ft_strlen(map->raw_map[column]);
		if (len > max_x)
			max_x = len;
		column++;
	}
	map->grid = malloc(sizeof(char *) * (column + 3)); // for null
	if (!map->grid)
		error_exit_all("Malloc Error", header, map);
	while (++y < column + 2)
		map->grid[y] = ft_grid_maker(sizeof(char), (max_x + 2), map, header);
	map->grid[y] = NULL;
	fill_grid(map);
	map->height = y;
	map->width = max_x + 2;
}

static void	info(t_map *map, t_header *header)
{
	int	i;
	int	j;

	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (map->raw_map[i][j] == 'N')
				map->orientation = N;
			else if (map->raw_map[i][j] == 'S')
				map->orientation = S;
			else if (map->raw_map[i][j] == 'W')
				map->orientation = W;
			else if (map->raw_map[i][j] == 'E')
				map->orientation = E;
		}
	}
	map->player_x = j;
	map->player_y = i;
	make_grid(map, header);
}

void	map_parse(t_map *map, t_header *header)
{
	char	**cpy_map;

	is_chars_valid(map, header);
	is_empty_line(map, header);
	info(map, header);
	cpy_map = make_copy(map, header);
	copy_mapcontrol_space(map, cpy_map, header);
	free_2d_array(cpy_map);
	// free_2d_array(map->raw_map); FOR DEBUG
}
