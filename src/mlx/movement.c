/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:30:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/10 17:55:00 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == XK_w || keycode == XK_W)
		mlx->keys.w = 1;
	if (keycode == XK_s || keycode == XK_S)
		mlx->keys.s = 1;
	if (keycode == XK_a || keycode == XK_A)
		mlx->keys.a = 1;
	if (keycode == XK_d || keycode == XK_D)
		mlx->keys.d = 1;
	if (keycode == XK_Left)
		mlx->keys.left = 1;
	if (keycode == XK_Right)
		mlx->keys.right = 1;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w || keycode == XK_W)
		mlx->keys.w = 0;
	if (keycode == XK_s || keycode == XK_S)
		mlx->keys.s = 0;
	if (keycode == XK_a || keycode == XK_A)
		mlx->keys.a = 0;
	if (keycode == XK_d || keycode == XK_D)
		mlx->keys.d = 0;
	if (keycode == XK_Left)
		mlx->keys.left = 0;
	if (keycode == XK_Right)
		mlx->keys.right = 0;
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

static void	move_player(t_mlx *mlx, double move_x, double move_y)
{
	int		new_x;
	int		new_y;
	t_map	*map;

	map = mlx->map;

	//if (map->grid[new_y][(int)map->player.x] != '1')
		map->player.y += 1;
	//if (map->grid[(int)map->player.y][new_x] != '1')
		map->player.x += move_x;
}

int	update_game(t_mlx *mlx)
{
	if (mlx->keys.w || mlx->keys.up)
		move_player(mlx, mlx->map->player.x * MOVE_SPEED, mlx->map->player.y
			* MOVE_SPEED);
	if (mlx->keys.s || mlx->keys.down)
		move_player(mlx, -mlx->map->player.y * MOVE_SPEED, -mlx->map->player.y
			* MOVE_SPEED);
	if (mlx->keys.left || mlx->keys.a)
		rotate_player(&mlx->map->player, ROT_SPEED);
	if (mlx->keys.right || mlx->keys.d)
		rotate_player(&mlx->map->player, -ROT_SPEED);
	return (0);
}
