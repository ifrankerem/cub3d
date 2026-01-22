/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:25 by buket             #+#    #+#             */
/*   Updated: 2025/12/27 15:40:12 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_control(void *img, t_mlx *mlx)
{
	if (!img)
		error_exit_all("Texture loading failed!", mlx->header, mlx->map, mlx);
}

static void	ft_set_orientation(t_map *map)
{
	if (map->orientation == E)
	{
		map->player.dir_x = 1;
		map->player.dir_y = 0;
	}
	if (map->orientation == N)
	{
		map->player.dir_x = 0;
		map->player.dir_y = -1;
	}
	if (map->orientation == W)
	{
		map->player.dir_x = -1;
		map->player.dir_y = 0;
	}
	if (map->orientation == S)
	{
		map->player.dir_x = 0;
		map->player.dir_y = +1;
	}
}

static void	ft_set_plane(t_map *map)
{
	double	plane_length;

	plane_length = tan(FOV_DEG * M_PI / 180.0 / 2);
	if (map->orientation == E)
	{
		map->player.plane_x = 0;
		map->player.plane_y = plane_length;
	}
	if (map->orientation == N)
	{
		map->player.plane_x = plane_length;
		map->player.plane_y = 0;
	}
	if (map->orientation == W)
	{
		map->player.plane_x = 0;
		map->player.plane_y = -plane_length;
	}
	if (map->orientation == S)
	{
		map->player.plane_x = -plane_length;
		map->player.plane_y = 0;
	}
}

static void	player_init_2(t_player *player)
{
	player->perp_wall_dist = 0;
	player->side_dist_x = 0;
	player->side_dist_y = 0;
	player->wall_hit = 0;
	player->map_x = 0;
	player->map_y = 0;
	player->step_x = 0;
	player->step_y = 0;
	player->delta_dist_x = fabs(1 / player->raydir_x);
	player->delta_dist_y = fabs(1 / player->raydir_y);
}

void	player_init(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
			{
				map->player.x = x + 0.5;
				map->player.y = y + 0.5;
				ft_set_orientation(map);
				ft_set_plane(map);
				player_init_2(&map->player);
				return ;
			}
			x++;
		}
		y++;
	}
}
