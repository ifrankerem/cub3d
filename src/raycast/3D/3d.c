/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 01:21:41 by iarslan           #+#    #+#             */
/*   Updated: 2025/12/27 15:36:44 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_to_hex(int rgb[3])
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

static void	convert_colors(t_header *header, t_textures *tex)
{
	tex->floor_color = rgb_to_hex(header->f_rgb);
	tex->ceiling_color = rgb_to_hex(header->c_rgb);
}

static double	get_wall_x(t_player *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = ray->y + ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = ray->x + ray->perp_wall_dist * ray->raydir_x;
	return (wall_x);
}

void	get_info_from_draw(t_draw_info *draw, t_player *ray,
		t_textures *textures)
{
	double	wall_x;

	draw->tex = get_texture(ray, textures);
	wall_x = get_wall_x(ray);
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * draw->tex->width);
	if ((ray->side == 0 && ray->raydir_x < 0) || (ray->side == 1
			&& ray->raydir_y < 0))
		draw->tex_x = draw->tex->width - draw->tex_x - 1;
	draw->step = 1.0 * draw->tex->height / ray->line_height;
	draw->tex_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2)
		* draw->step;
}

int	ft_3d(t_mlx *mlx)
{
	int			x;
	t_player	ray;
	t_draw_info	draw;

	x = -1;
	ft_calc_fps(&mlx->map->player);
	init_draw(&draw);
	update_game(mlx);
	convert_colors(mlx->header, mlx->tex);
	while (++x < WIN_W)
	{
		ray = mlx->map->player;
		ft_ray_maker(&ray, x, WIN_W);
		ft_dda(&ray, mlx->map);
		ft_wall_dist(&ray);
		ft_line_height(&ray);
		get_info_from_draw(&draw, &ray, mlx->tex);
		start_draw(&ray, x, mlx, &draw);
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0, 0);
	return (0);
}
