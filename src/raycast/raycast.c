/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 02:55:45 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/29 15:56:47 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void calculate_sideDist(t_player *player)
{
	player->mapX = (int)player->x;
	player->mapY = (int)player->y;
	if (player->rayDirX < 0)
	{
		player->stepX = -1;
		player->sideDistX = (player->x - player->mapX) * player->deltaDistX;
	}
	else
	{
		player->stepX = 1;
		player->sideDistX = (player->mapX + 1.0 - player->x) * player->deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		player->stepY = -1;
		player->sideDistY = (player->y - player->mapY) * player->deltaDistY;
	}
	else
	{
		player->stepY = 1;
		player->sideDistY = (player->mapY + 1.0 - player->y) * player->deltaDistY;
	}
}

void	ft_dda(t_player *player, t_map *map)
{
	calculate_sideDist(player);
	while (player->wall_hit == 0)
	{
		if (player->sideDistX < player->sideDistY)
		{
			player->sideDistX += player->deltaDistX;
			player->mapX += player->stepX;
			player->side = 0; // dikey eksende bir duvara çarptı x = a için bir dogru gibi düsün
		}
		else
		{
			player->sideDistY += player->deltaDistY;
			player->mapY += player->stepY;
			player->side = 1; // yatay eksende bir duvara çarptı y = a için bir dogru gibi düsün
		}
		if (player->mapX >= map->width || player->mapY >= map->height
			|| player->mapX < 0 || player->mapY < 0)
		{
			player->wall_hit = 1;
			return ;
		}
		if (map->grid[player->mapY][player->mapX] == '1')
			player->wall_hit = 1;
	}
}
