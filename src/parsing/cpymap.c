/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:12:48 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/02 03:14:19 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**make_copy(t_map *map)
{
	char	**cpy_map;
	int		x;
	int		y;

	y = 0;
	cpy_map = (char **)malloc(sizeof(char *) * (map->line_number + 1));
	if (!cpy_map)
		ft_error(map, 8);
	while (map->map[y])
	{
		x = 0;
		cpy_map[y] = (char *)malloc(sizeof(char) * (map->column_number) + 1);
		if (!(cpy_map[y]))
			ft_error(map, 8);
		while (map->map[y][x])
		{
			cpy_map[y][x] = map->map[y][x];
			x++;
		}
		cpy_map[y][x] = '\0';
		y++;
	}
	cpy_map[y] = '\0';
	return (cpy_map);
}

void	copy_mapcontrol_player(t_map *map, char **cpy_map)
{
	int	x;
	int	y;

	y = 0;
	flood_fill_player(cpy_map, map);
	while (cpy_map[y])
	{
		x = 0;
		while (cpy_map[y][x])
		{
			if (cpy_map[y][x] == 'C')
			{
				free_cpymap(cpy_map);
				ft_error(map, 7);
			}
			x++;
		}
		y++;
	}
}

void	copy_mapcontrol_exit(t_map *map, char **cpy_map2)
{
	int	x;
	int	y;

	y = 0;
	flood_fill_for_exit(cpy_map2, map);
	while (cpy_map2[y])
	{
		x = 0;
		while (cpy_map2[y][x])
		{
			if (cpy_map2[y][x] == 'C')
			{
				free_cpymap(cpy_map2);
				ft_error(map, 7);
			}
			x++;
		}
		y++;
	}
}
