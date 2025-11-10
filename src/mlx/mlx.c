/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:24:37 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/10 17:37:30 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_window(t_mlx *mlx, t_map *map, t_header *header)
{
	mlx->ptr = mlx_init();
	if (!(mlx->ptr))
		error_exit_all("MLX error!", header, map);
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, "cub3D");
	if (!mlx->win)
		return (mlx_destroy_display(mlx->ptr), free(mlx->ptr),
			error_exit_all("MLX error!", header, map));
	ft_2d_init(mlx); // for2d
}

// void	player_move(t_player *player, int key)
// {
// 	if (key == UP)
// 		player->y -= 1;
// 	if (key == DOWN)
// 		player->y += 1;
// 	if (key == RIGHT)
// 	{
// 		player->dirX = player->dirX * cos(-ROT_SPEED) - player->dirY
// 			* sin(-ROT_SPEED);
// 		player->dirY = player->dirX * cos(-ROT_SPEED) + player->dirY
// 			* sin(-ROT_SPEED);
// 		player->planeX = player->planeX * cos(-ROT_SPEED) - player->planeY
// 			* sin(-ROT_SPEED);
// 		player->dirY = player->planeX * cos(-ROT_SPEED) + player->planeY
// 			* sin(-ROT_SPEED);
// 	}
// 	if (key == LEFT)
// 	{
// 		player->dirX = player->dirX * cos(ROT_SPEED) - player->dirY
// 			* sin(ROT_SPEED);
// 		player->dirY = player->dirX * cos(ROT_SPEED) + player->dirY
// 			* sin(ROT_SPEED);
// 		player->planeX = player->planeX * cos(ROT_SPEED) - player->planeY
// 			* sin(ROT_SPEED);
// 		player->dirY = player->planeX * cos(ROT_SPEED) + player->planeY
// 			* sin(ROT_SPEED);
// 	}
// }

// int	movement_and_exit(int keysym, t_mlx *mlx)
// {
// 	if (keysym == XK_Escape)
// 	{
// 		printf("Quitting game by pressing ESC\n");
// 		close_window(mlx);
// 	}
// 	if (keysym == XK_Up || keysym == XK_w)
// 		player_move(&mlx->map->player, UP);
// 	if (keysym == XK_Left || keysym == XK_a)
// 		player_move(&mlx->map->player, LEFT);
// 	if (keysym == XK_Down || keysym == XK_s)
// 		player_move(&mlx->map->player, DOWN);
// 	if (keysym == XK_Right || keysym == XK_d)
// 		player_move(&mlx->map->player, RIGHT);
// 	draw_loop(mlx);
// 	return (0);
// }

int	close_window(t_mlx *mlx)
{
	// mlx_destroy_image(map->mlx_ptr, map->player);
	// mlx_destroy_image(map->mlx_ptr, map->coin);
	// mlx_destroy_image(map->mlx_ptr, map->background);
	// mlx_destroy_image(map->mlx_ptr, map->exit);
	// mlx_destroy_image(map->mlx_ptr, map->wall);
	// mlx_destroy_window(map->mlx_ptr, map->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	cleanup_all(mlx->header, mlx->map);
	exit(0);
}
