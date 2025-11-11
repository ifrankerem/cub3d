/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:30:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/12 01:24:28 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		mlx->keys.w = 1;
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		mlx->keys.s = 1;
	if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		mlx->keys.a = 1;
	if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		mlx->keys.d = 1;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		mlx->keys.w = 0;
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		mlx->keys.s = 0;
	if (keycode == XK_a || keycode == XK_A || keycode == XK_Left)
		mlx->keys.a = 0;
	if (keycode == XK_d || keycode == XK_D || keycode == XK_Right)
		mlx->keys.d = 0;
	return (0);
}

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

static void	move_player(t_mlx *mlx, int key)
{
	t_map	*map;
	double	newX;
	double	newY;

	map = mlx->map;
	// vektör toplaması
	if (key == UP)
	{
		newX = map->player.x + map->player.dirX * MOVE_SPEED;
		newY = map->player.y + map->player.dirY * MOVE_SPEED;
	}
	if (key == DOWN)
	{
		newX = map->player.x - map->player.dirX * MOVE_SPEED;
		newY = map->player.y - map->player.dirY * MOVE_SPEED;
	}
	if (map->grid[(int)newY][(int)newX] != '1')
	{
		map->player.x = newX;
		map->player.y = newY;
	}
}

int	update_game(t_mlx *mlx)
{
	if (mlx->keys.w)
		move_player(mlx, UP);
	if (mlx->keys.s)
		move_player(mlx, DOWN);
	if (mlx->keys.a)
		rotate_player(&mlx->map->player, -ROT_SPEED);
	if (mlx->keys.d)
		rotate_player(&mlx->map->player, ROT_SPEED);
	return (0);
}
