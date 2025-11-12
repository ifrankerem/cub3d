/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 02:55:45 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/13 01:20:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_maker(t_player *player, int x, int screen_width)
{
	double	cameraX;

	cameraX = 2 * x / (double)screen_width - 1; // en sol -1 orta 0 en sağ + 1
	player->rayDirX = player->dirX + player->planeX * cameraX;
	player->rayDirY = player->dirY + player->planeY * cameraX;
	player->deltaDistX = fabs(1.0 / player->rayDirX);
	player->deltaDistY = fabs(1.0 / player->rayDirY);
}

void	ft_dda(t_player *player, t_map *map)
{
	int	stepX;
	int	stepY;
	int	mapX;
	int	mapY;

	mapX = (int)player->x;
	mapY = (int)player->y;
	if (player->rayDirX < 0)
	{
		stepX = -1;
		player->sideDistX = (player->x - mapX) * player->deltaDistX;
	}
	else
	{
		stepX = 1;
		player->sideDistX = (mapX + 1.0 - player->x) * player->deltaDistX;
	}
	if (player->rayDirY < 0)
	{
		stepY = -1;
		player->sideDistY = (player->y - mapY) * player->deltaDistY;
	}
	else
	{
		stepY = 1;
		player->sideDistY = (mapY + 1.0 - player->y) * player->deltaDistY;
	}
	while (player->wall_hit == 0)
	{
		if (player->sideDistX < player->sideDistY)
		{
			player->sideDistX += player->deltaDistX;
			mapX += stepX;
			player->side = 0;
			// dikey eksende bir duvara çarptı x = a için bir dogru gibi düsün
		}
		else
		{
			player->sideDistY += player->deltaDistY;
			mapY += stepY;
			player->side = 1;
			// yatay eksende bir duvara çarptı y = a için bir dogru gibi düsün
		}
		if (map->grid[mapY][mapX] == '1')
			player->wall_hit = 1;
	}
}

void	ft_wall_dist(t_player *player)
{
	if (player->side == 0)
		player->perpWallDist = player->sideDistX - player->deltaDistX;
	else
		player->perpWallDist = player->sideDistY - player->deltaDistY;
}

void	ft_line_height(t_player *player, t_map *map)
{
	player->line_height = (int)(WIN_H / player->perpWallDist);
	player->drawStart = -player->line_height / 2 + WIN_H / 2;
	if (player->drawStart < 0)
		player->drawStart = 0;
	player->drawEnd = player->line_height / 2 + WIN_H / 2;
	if (player->drawEnd >= WIN_H)
		player->drawEnd = WIN_H - 1;
}

t_texture	*get_texture(t_player *player, t_textures *tex)
{
	if (player->side == 0)
	{
		if (player->rayDirX > 0)
			return (&tex->east);
		else
			return (&tex->west);
	}
	else
	{
		if (player->rayDirY > 0)
			return (&tex->south);
		else
			return (&tex->north);
	}
}