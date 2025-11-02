/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 01:33:28 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/02 01:33:44 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_player(char **cpy_map, int x, int y)
{
	if (cpy_map[y][x] == '1' || cpy_map[y][x] == 'X' || cpy_map[y][x] == 'E')
		return ;
	cpy_map[y][x] = 'X';
	fill_player(cpy_map, x + 1, y);
	fill_player(cpy_map, x - 1, y);
	fill_player(cpy_map, x, y + 1);
	fill_player(cpy_map, x, y - 1);
}

void	fill_exit(char **cpy_map, int x, int y)
{
	if (cpy_map[y][x] == '1' || cpy_map[y][x] == 'X')
		return ;
	cpy_map[y][x] = 'X';
	fill_exit(cpy_map, x + 1, y);
	fill_exit(cpy_map, x - 1, y);
	fill_exit(cpy_map, x, y + 1);
	fill_exit(cpy_map, x, y - 1);
}

void	flood_fill_player(char **cpy_map, t_map *map)
{
	fill_player(cpy_map, map->player_x, map->player_y);
}

void	flood_fill_for_exit(char **cpy_map2, t_map *map)
{
	fill_exit(cpy_map2, map->exit_x, map->exit_y);
}
