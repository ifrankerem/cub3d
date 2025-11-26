/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:30:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/26 17:15:02 by buket            ###   ########.fr       */
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
	if (keycode == XK_a || keycode == XK_A)
		mlx->keys.a = 1;
	if (keycode == XK_d || keycode == XK_D)
		mlx->keys.d = 1;
	if (keycode == XK_Right)
		mlx->keys.right = 1;
	if (keycode == XK_Left)
		mlx->keys.left = 1;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		mlx->keys.w = 0;
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		mlx->keys.s = 0;
	if (keycode == XK_a || keycode == XK_A)
		mlx->keys.a = 0;
	if (keycode == XK_d || keycode == XK_D)
		mlx->keys.d = 0;
	if (keycode == XK_Right)
		mlx->keys.right = 0;
	if (keycode == XK_Left)
		mlx->keys.left = 0;
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
		newX = map->player.x + map->player.dirX * mlx->map->player.move_speed;
		newY = map->player.y + map->player.dirY * mlx->map->player.move_speed;
	}
	if (key == DOWN)
	{
		newX = map->player.x - map->player.dirX * mlx->map->player.move_speed;
		newY = map->player.y - map->player.dirY * mlx->map->player.move_speed;
	}
	if(key == RIGHT)
	{
		newX = map->player.x - map->player.dirY * mlx->map->player.move_speed;
		newY = map->player.y + map->player.dirX * mlx->map->player.move_speed;
	}
	if(key == LEFT)
	{
		newX = map->player.x + map->player.dirY * mlx->map->player.move_speed;
		newY = map->player.y - map->player.dirX * mlx->map->player.move_speed;
	}
	if(newX >= WIN_W || newY >= WIN_H || newX<0 || newY<0)
		return;
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
	if(mlx->keys.right)
		rotate_player(&mlx->map->player, mlx->map->player.rot_speed);
	if(mlx->keys.left)
		rotate_player(&mlx->map->player, -mlx->map->player.rot_speed);
	return (0);
}
