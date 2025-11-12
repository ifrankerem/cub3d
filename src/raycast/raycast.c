/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 02:55:45 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/12 05:21:35 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_maker(t_player *player, int x, int screen_width)
{
	double	cameraX;

	cameraX = 2 * x / (double)screen_width - 1; // en sol -1 orta 0 en sağ + 1
	player->rayDirX = player->dirX + player->planeX * cameraX;
	player->rayDirY = player->dirY + player->planeY * cameraX;
}

void	ft_dda(t_player *player, t_map *map)
{
	double	deltaDistX;
	double	deltaDistY;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
	double	posX;
	double	posY;

	posX = player->x;
	posY = player->y;
	mapX = (int)posX;
	mapY = (int)posY;
	player->sideDistX = 0;
	player->sideDistY = 0;
	player->wall_hit = 0;
	deltaDistX = fabs(1 / player->rayDirX);
	deltaDistY = fabs(1 / player->rayDirY);
	if (player->rayDirX < 0)
	{
		stepX = -1;
		player->sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		player->sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		stepY = -1;
		player->sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		player->sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}
	while (player->wall_hit)
	{
		if (deltaDistX < deltaDistY)
		{
			player->sideDistX += deltaDistX;
			mapX += stepX;
			player->side = 0;
		}
		else
		{
			player->sideDistY += deltaDistY;
			mapY += stepY;
			player->side = 1;
		}
		if (map->grid[(int)player->sideDistY][(int)player->sideDistX] == '1')
			player->wall_hit = 1;
	}
}
