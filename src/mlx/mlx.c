/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:24:37 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/12 01:20:39 by iarslan          ###   ########.fr       */
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
	printf("%f", mlx->map->player.x);
	printf("%f", mlx->map->player.x);
	ft_2d_init(mlx); // for2d
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
