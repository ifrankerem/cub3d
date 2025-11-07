/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:24:37 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/07 02:24:11 by iarslan          ###   ########.fr       */
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
	// todo init xpm images!
}

int	movement_and_exit(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		printf("Quitting game by pressing ESC\n");
		close_window(mlx);
	}
	// if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
	// 	player_move(map, -1, 0);
	// if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
	// 	player_move(map, 0, -1);
	// if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
	// 	player_move(map, 1, 0);
	// if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
	// 	player_move(map, 0, 1);
	return (0);
}

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
// void	movement(void);
