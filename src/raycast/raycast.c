/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 02:55:45 by iarslan           #+#    #+#             */
/*   Updated: 2025/12/27 15:51:16 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map_variables(t_player *player)
{
	player->map_x = (int)player->x;
	player->map_y = (int)player->y;
}

void	calculate_side_dist(t_player *player)
{
	init_map_variables(player);
	if (player->raydir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->x - player->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->x)
			* player->delta_dist_x;
	}
	if (player->raydir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->y - player->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->y)
			* player->delta_dist_y;
	}
}

void	ft_dda(t_player *player, t_map *map)
{
	calculate_side_dist(player);
	while (player->wall_hit == 0)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (player->map_x >= map->width || player->map_y >= map->height
			|| player->map_x < 0 || player->map_y < 0)
		{
			player->wall_hit = 1;
			return ;
		}
		if (map->grid[player->map_y][player->map_x] == '1')
			player->wall_hit = 1;
	}
}
