/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:23:36 by buket             #+#    #+#             */
/*   Updated: 2025/12/27 15:36:44 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	get_pixel(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
	return (*(int *)pixel);
}

void	start_draw(t_player *ray, int x, t_mlx *mlx, t_draw_info *draw)
{
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		if (y < ray->draw_start)
			put_pixel(&mlx->img, x, y, mlx->tex->ceiling_color);
		else if (y <= ray->draw_end && y >= ray->draw_start)
		{
			draw->tex_y = (int)draw->tex_pos % draw->tex->height;
			draw->tex_pos += draw->step;
			put_pixel(&mlx->img, x, y, get_pixel(draw->tex, draw->tex_x,
					draw->tex_y));
		}
		else
			put_pixel(&mlx->img, x, y, mlx->tex->floor_color);
	}
}
