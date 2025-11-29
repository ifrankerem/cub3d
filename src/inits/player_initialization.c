/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 12:42:25 by buket             #+#    #+#             */
/*   Updated: 2025/11/29 15:49:41 by buket            ###   ########.fr       */
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
		map->player.dirX = 1;
		map->player.dirY = 0;
	}
	if (map->orientation == N)
	{
		map->player.dirX = 0;
		map->player.dirY = -1;
	}
	if (map->orientation == W)
	{
		map->player.dirX = -1;
		map->player.dirY = 0;
	}
	if (map->orientation == S)
	{
		map->player.dirX = 0;
		map->player.dirY = +1;
	}
}

static void	ft_set_plane(t_map *map)
{
	double	plane_length;

	plane_length = tan(FOV_DEG * M_PI / 180.0 / 2);
	if (map->orientation == E)
	{
		map->player.planeX = 0;
		map->player.planeY = -plane_length;
	}
	if (map->orientation == N)
	{
		map->player.planeX = plane_length;
		map->player.planeY = 0;
	}
	if (map->orientation == W)
	{
		map->player.planeX = 0;
		map->player.planeY = plane_length;
	}
	if (map->orientation == S)
	{
		map->player.planeX = -plane_length;
		map->player.planeY = 0;
	}
}

static void	player_init_2(t_player *player)
{
	player->perpWallDist = 0;
	player->sideDistX = 0;
	player->sideDistY = 0;
	player->wall_hit = 0;
	player->mapX = 0;
	player->mapY = 0;
	player->stepX = 0;
	player->stepY = 0;
	player->deltaDistX = fabs(1 / player->rayDirX);
	player->deltaDistY = fabs(1 / player->rayDirY);
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
				return ;
			}
			x++;
		}
		y++;
	}
	player_init_2(&map->player);
}
