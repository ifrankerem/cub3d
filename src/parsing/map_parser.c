/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:30:11 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/29 15:14:26 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	map->height = column + 2; // Önce height'ı hesapla
	map->width = max_x + 2;
	map->grid = malloc(sizeof(char *) * (column + 3)); // for null
	if (!map->grid)
		error_exit_all("Malloc Error", header, map, NULL);
	while (++y < column + 2)
		map->grid[y] = ft_grid_maker(sizeof(char), (max_x + 2), map, header);
	map->grid[y] = NULL; // Şimdi NULL terminator'ı ekle
	fill_grid(map);
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
	make_grid(map, header);
}

void	map_parse(t_map *map, t_header *header)
{
	char	**cpy_map;

	is_chars_valid(map, header);
	is_empty_line(map, header);
	info(map, header);
	is_map_closed(map, header);
	cpy_map = make_copy(map, header);
	copy_mapcontrol_space(map, cpy_map, header);
	free_2d_array(cpy_map);
}
