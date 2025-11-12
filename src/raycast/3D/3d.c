/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:21:41 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/13 02:09:31 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_3d(t_mlx *mlx, t_textures *tex)
{
	int			x;
	int			y;
	t_player	ray;

	x = -1;
	y = -1;
	while (++x <= WIN_W)
	{
		ray = mlx->map->player;
		ft_ray_maker(&ray, x, WIN_W);
		ft_dda(&ray, mlx->map);
		ft_wall_dist(&ray);
		ft_line_height(ray, mlx->map);
		while (++y <= WIN_H)
		{
			if (y < ray.drawStart)
			{
				put_pixel()
			}
			else if (y <= ray.drawEnd && y >= ray.drawStart)
			{
			}
			else
				put_pixel()
		}
	}
}
