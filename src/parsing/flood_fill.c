/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:33:28 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/09 19:55:43 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_space(char **cpy_map, int x, int y, t_map *map)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return ;
	if (!ft_isspace(cpy_map[y][x]))
		return ;
	cpy_map[y][x] = 'X';
	fill_space(cpy_map, x + 1, y, map);
	fill_space(cpy_map, x - 1, y, map);
	fill_space(cpy_map, x, y + 1, map);
	fill_space(cpy_map, x, y - 1, map);
}

void	flood_fill_for_space(char **cpy_map, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_isspace(cpy_map[y][x]))
				fill_space(cpy_map, x, y, map);
			x++;
		}
		y++;
	}
}
