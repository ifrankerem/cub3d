/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 03:12:48 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/03 22:44:12 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**make_copy(t_map *map)
{
	char	**cpy_map;
	int		x;
	int		y;

	y = 0;
	cpy_map = (char **)malloc(sizeof(char *) * (map->width + 1));
	if (!cpy_map)
		error_map_exit("Error\n Malloc Error!\n", map);
	while (map->grid[y])
	{
		x = 0;
		cpy_map[y] = (char *)malloc(sizeof(char) * (map->height) + 1);
		if (!(cpy_map[y]))
			error_map_exit("Error\n Malloc Error!\n", map);
		while (map->grid[y][x])
		{
			cpy_map[y][x] = map->grid[y][x];
			x++;
		}
		cpy_map[y][x] = '\0';
		y++;
	}
	cpy_map[y] = '\0';
	return (cpy_map);
}

// void	copy_mapcontrol_player(t_map *map, char **cpy_map)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	flood_fill_player(cpy_map, map);
// 	while (cpy_map[y])
// 	{
// 		x = 0;
// 		while (cpy_map[y][x])
// 		{
// 			if (cpy_map[y][x] == '0')
// 			{
// 				free_cpymap(cpy_map);
// 				error_map_exit("There is space which is not covered!", map);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	copy_mapcontrol_space(t_map *map, char **cpy_map2)
{
	int	x;
	int	y;

	y = 0;
	flood_fill_for_space(cpy_map2, map);
	while (cpy_map2[y])
	{
		x = 0;
		while (cpy_map2[y][x])
		{
			if (cpy_map2[y][x] == 'N' || cpy_map2[y][x] == 'S'
				|| cpy_map2[y][x] == 'E' || cpy_map2[y][x] == 'W'
				|| cpy_map2[y][x] == '0')
			{
				free_cpymap(cpy_map2);
				error_map_exit("Error\nThere is space which is not covered!\n", map);
			}
			x++;
		}
		y++;
	}
}

void	free_cpymap(char **cpy_map)
{
	int	i;

	i = 0;
	if (!cpy_map)
		return ;
	while (cpy_map[i])
	{
		free(cpy_map[i]);
		i++;
	}
	free(cpy_map);
}
