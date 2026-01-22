/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_scnd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:55:40 by buket             #+#    #+#             */
/*   Updated: 2025/12/27 15:36:44 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ray_maker(t_player *player, int x, int screen_width)
{
	double	camera_x;

	camera_x = 2 * x / (double)screen_width - 1;
	player->raydir_x = player->dir_x + player->plane_x * camera_x;
	player->raydir_y = player->dir_y + player->plane_y * camera_x;
	player->delta_dist_x = fabs(1.0 / player->raydir_x);
	player->delta_dist_y = fabs(1.0 / player->raydir_y);
}

void	ft_wall_dist(t_player *player)
{
	if (player->side == 0)
		player->perp_wall_dist = player->side_dist_x - player->delta_dist_x;
	else
		player->perp_wall_dist = player->side_dist_y - player->delta_dist_y;
}

void	ft_line_height(t_player *player)
{
	player->line_height = (int)(WIN_H / player->perp_wall_dist);
	player->draw_start = -player->line_height / 2 + WIN_H / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + WIN_H / 2;
	if (player->draw_end >= WIN_H)
		player->draw_end = WIN_H - 1;
}

t_texture	*get_texture(t_player *player, t_textures *tex)
{
	if (player->side == 0)
	{
		if (player->raydir_x > 0)
			return (&tex->east);
		else
			return (&tex->west);
	}
	else
	{
		if (player->raydir_y > 0)
			return (&tex->south);
		else
			return (&tex->north);
	}
}
