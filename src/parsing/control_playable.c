/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_playable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:35:43 by bucolak           #+#    #+#             */
/*   Updated: 2025/12/27 15:46:04 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ff_playable(char **cpy_map, int x, int y, t_map *map)
{
	if (y < 0 || y >= map->height || x < 0 || x >= map->width)
		return ;
	if (cpy_map[y][x] != '0' && cpy_map[y][x] != '1')
		return ;
	cpy_map[y][x] = 'Y';
	ff_playable(cpy_map, x + 1, y, map);
	ff_playable(cpy_map, x - 1, y, map);
	ff_playable(cpy_map, x, y + 1, map);
	ff_playable(cpy_map, x, y - 1, map);
}

int	is_map_multipel(char **cpy_map)
{
	int	i;
	int	j;

	i = -1;
	while (cpy_map[++i])
	{
		j = -1;
		while (cpy_map[i][++j])
		{
			if (cpy_map[i][j] == '0' || cpy_map[i][j] == '1')
				return (0);
		}
	}
	return (1);
}
