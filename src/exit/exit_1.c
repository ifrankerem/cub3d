/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:41:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/03 22:33:42 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_exit_header(char *error_message, t_header *init)
{
	int	i;

	i = 0;
	if (init->ea_path)
		free(init->ea_path);
	if (init->no_path)
		free(init->no_path);
	if (init->so_path)
		free(init->so_path);
	if (init->we_path)
		free(init->we_path);
	printf("%s", error_message);
	exit(1);
}

void	error_map_exit(char *error_message, t_map *init_map)
{
	int	i;

	i = 0;
	if (init_map->raw_map)
	{
		while (init_map->raw_map[i])
		{
			free(init_map->raw_map[i]);
			i++;
		}
		free(init_map->raw_map);
	}
	if (init_map->grid)
	{
		while (init_map->grid[i])
		{
			free(init_map->grid[i]);
			i++;
		}
		free(init_map->grid);
	}
	printf("%s", error_message);
	exit(1);
}
