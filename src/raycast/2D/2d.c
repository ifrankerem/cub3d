/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 01:02:17 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/09 21:16:40 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_2d_init(t_mlx *mlx)
{
	mlx->img.img = mlx_new_image(mlx->ptr, WIN_W, WIN_H);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
}

void	draw_square(t_img *img, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_mlx *mlx, int tile_size)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (mlx->map->grid[y][x] == '1')
				color = 0xff0a0a;
			else if (mlx->map->grid[y][x] == '0')
				color = 0xffffff;
			else
				color = 0x000000;
			draw_square(&mlx->img, x * tile_size, y * tile_size, tile_size,
				color);
			x++;
		}
		y++;
	}
}

void	draw_player(t_mlx *mlx, int tile_size)
{
	draw_square(&mlx->img, mlx->map->player.x * tile_size, mlx->map->player.y
		* tile_size, tile_size, 0x06a54b);
}



int	draw_loop(t_mlx *mlx)
{
	int tile_size;

	tile_size = 64;
	draw_map(mlx, tile_size);
	draw_player(mlx, tile_size);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	return (0);
}