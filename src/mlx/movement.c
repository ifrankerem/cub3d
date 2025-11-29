/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:30:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/29 15:39:00 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dirX;
	old_plane_x = player->planeX;
	player->dirX = player->dirX * cos(angle) - player->dirY * sin(angle);
	player->dirY = old_dir_x * sin(angle) + player->dirY * cos(angle);
	player->planeX = player->planeX * cos(angle) - player->planeY * sin(angle);
	player->planeY = old_plane_x * sin(angle) + player->planeY * cos(angle);
}

static void key_control(t_map *map, int key, double *newX, double *newY)
{
	if (key == UP)
	{
		*newX = map->player.x + map->player.dirX * map->player.move_speed;
		*newY = map->player.y + map->player.dirY * map->player.move_speed;
	}
	if (key == DOWN)
	{
		*newX = map->player.x - map->player.dirX * map->player.move_speed;
		*newY = map->player.y - map->player.dirY * map->player.move_speed;
	}
	if (key == RIGHT)
	{
		*newX = map->player.x - map->player.dirY * map->player.move_speed;
		*newY = map->player.y + map->player.dirX * map->player.move_speed;
	}
	if (key == LEFT)
	{
		*newX = map->player.x + map->player.dirY * map->player.move_speed;
		*newY = map->player.y - map->player.dirX * map->player.move_speed;
	}
}

static void	move_player(t_mlx *mlx, int key)
{
	t_map	*map;
	double	newX;
	double	newY;

	map = mlx->map;
	if (!map || !map->grid)
		return ;
	newX = map->player.x;
	newY = map->player.y;
	key_control(map, key, &newX, &newY);
	if (newX >= map->width || newY >= map->height || newX < 0 || newY < 0)
		return ;
	// wall sliding
	if (map->grid[(int)newY][(int)map->player.x] != '1')
		map->player.y = newY;
	if (map->grid[(int)map->player.y][(int)newX] != '1')
		map->player.x = newX;
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
