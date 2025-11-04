/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:33:28 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/04 03:15:26 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	fill_player(char **cpy_map, int x, int y)
// {
// 	if (cpy_map[y][x] == '1' || cpy_map[y][x] == 'X' || cpy_map[y][x] == 'E')
// 		return ;
// 	cpy_map[y][x] = 'X';
// 	fill_player(cpy_map, x + 1, y);
// 	fill_player(cpy_map, x - 1, y);
// 	fill_player(cpy_map, x, y + 1);
// 	fill_player(cpy_map, x, y - 1);
// }

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
	fill_space(cpy_map, 0, 0, map);
}

// void	flood_fill_player(char **cpy_map, t_map *map)
// {
// 	fill_player(cpy_map, map->player_x, map->player_y);
// }
