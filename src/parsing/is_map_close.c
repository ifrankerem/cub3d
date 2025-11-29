/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:49:24 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/29 17:15:40 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_columns_closed(t_map *map)
{
	int	j;
	int	i;

	i = 0;
	while (map->raw_map[i])
	{
		if (map->raw_map[i][0] && map->raw_map[i][0] != '1'
			&& map->raw_map[i][0] != ' ' && map->raw_map[i][0] != '\n')
		{
			return (1);
		}
		j = 0;
		while (map->raw_map[i][j] && map->raw_map[i][j] != '\n')
			j++;
		if (j > 0 && map->raw_map[i][j - 1] != '1' && map->raw_map[i][j
			- 1] != ' ')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	is_raws_closed(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->raw_map[0][i])
	{
		if (map->raw_map[0][i] != '1' && map->raw_map[0][i] != ' '
			&& map->raw_map[0][i] != '\n')
		{
			return (1);
		}
		i++;
	}
	i = 0;
	while (map->raw_map[i])
		i++;
	i--;
	j = 0;
	while (map->raw_map[i][j] && map->raw_map[i][j] != '\n')
	{
		if (map->raw_map[i][j] != '1' && map->raw_map[i][j] != ' ')
		{
			return (1);
		}
		j++;
	}
	return (0);
}

void	is_map_closed(t_map *map, t_header *header)
{
	if (is_raws_closed(map) == 1 || is_columns_closed(map) == 1)
		error_exit_all("Map is not closed!", header, map, NULL);
}
