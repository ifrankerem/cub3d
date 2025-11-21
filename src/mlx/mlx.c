/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:24:37 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/16 01:02:04 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_window(t_mlx *mlx, t_map *map, t_header *header)
{
	if (!(mlx->ptr))
		error_exit_all("MLX error!", header, map);
	mlx->win = mlx_new_window(mlx->ptr, WIN_W, WIN_H, "cub3D");
	if (!mlx->win)
		return (mlx_destroy_display(mlx->ptr), free(mlx->ptr),
			error_exit_all("MLX error!", header, map));
	mlx->img.img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	if (!mlx->img.img)
		error_exit_all("MLX error!", header, map);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
	// ft_2d_init(mlx); // for2d
}

int	close_window(t_mlx *mlx)
{
	if (mlx->tex)
	{
		if (mlx->tex->north.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->north.img);
		if (mlx->tex->south.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->south.img);
		if (mlx->tex->east.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->east.img);
		if (mlx->tex->west.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->west.img);
	}
	if (mlx->img.img)
		mlx_destroy_image(mlx->ptr, mlx->img.img);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	cleanup_all(mlx->header, mlx->map);
	exit(0);
}
