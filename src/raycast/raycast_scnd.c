/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_scnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:55:40 by buket             #+#    #+#             */
/*   Updated: 2025/11/29 15:56:41 by buket            ###   ########.fr       */
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

void	ft_wall_dist(t_player *player)
{
	if (player->side == 0)
		player->perpWallDist = player->sideDistX - player->deltaDistX;
	else
		player->perpWallDist = player->sideDistY - player->deltaDistY;
}

void	ft_line_height(t_player *player)
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
