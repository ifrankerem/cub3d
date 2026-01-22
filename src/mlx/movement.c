/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:30:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/12/27 15:46:04 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

static void	key_control(t_map *map, int key, double *new_x, double *new_y)
{
	if (key == UP)
	{
		*new_x = map->player.x + map->player.dir_x * map->player.move_speed;
		*new_y = map->player.y + map->player.dir_y * map->player.move_speed;
	}
	if (key == DOWN)
	{
		*new_x = map->player.x - map->player.dir_x * map->player.move_speed;
		*new_y = map->player.y - map->player.dir_y * map->player.move_speed;
	}
	if (key == RIGHT)
	{
		*new_x = map->player.x - map->player.dir_y * map->player.move_speed;
		*new_y = map->player.y + map->player.dir_x * map->player.move_speed;
	}
	if (key == LEFT)
	{
		*new_x = map->player.x + map->player.dir_y * map->player.move_speed;
		*new_y = map->player.y - map->player.dir_x * map->player.move_speed;
	}
}

static void	move_player(t_mlx *mlx, int key)
{
	t_map	*map;
	double	new_x;
	double	new_y;

	map = mlx->map;
	if (!map || !map->grid)
		return ;
	new_x = map->player.x;
	new_y = map->player.y;
	key_control(map, key, &new_x, &new_y);
	if (new_x >= map->width || new_y >= map->height || new_x < 0 || new_y < 0)
		return ;
	if (map->grid[(int)new_y][(int)map->player.x] != '1')
		map->player.y = new_y;
	if (map->grid[(int)map->player.y][(int)new_x] != '1')
		map->player.x = new_x;
}

int	update_game(t_mlx *mlx)
{
	if (mlx->keys.w)
		move_player(mlx, UP);
	if (mlx->keys.s)
		move_player(mlx, DOWN);
	if (mlx->keys.a)
		move_player(mlx, LEFT);
	if (mlx->keys.d)
		move_player(mlx, RIGHT);
	if (mlx->keys.right)
		rotate_player(&mlx->map->player, mlx->map->player.rot_speed);
	if (mlx->keys.left)
		rotate_player(&mlx->map->player, -mlx->map->player.rot_speed);
	return (0);
}
