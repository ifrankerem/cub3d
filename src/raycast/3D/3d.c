// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   3d.c                                               :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/11/13 01:21:41 by iarslan           #+#    #+#             */
// /*   Updated: 2025/11/21 15:16:43 by iarslan          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

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

void	put_pixel(t_img *img, int x, int y, int color)
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

static double	get_wall_x(t_player *ray)
{
    double wall_x;

    if(ray->side == 0)
        wall_x = ray->y + ray->perpWallDist * ray->rayDirY;
    else
        wall_x = ray->x + ray->perpWallDist * ray->rayDirX;
    return wall_x;
}

void get_info_from_draw(t_draw_info *draw, t_player *ray, t_textures *textures)
{
    double wall_x;

    draw->tex = get_texture(ray, textures);
	wall_x = get_wall_x(ray);
    wall_x -= floor(wall_x);
    draw->tex_x = (int)(wall_x * draw->tex->width);
    draw->step = 1.0 * draw->tex->height / ray->line_height; // her ekran pixeli için texture'da ne kadar ilerleyeceğiz
    draw->texPos = (ray->drawStart - WIN_H/2 + ray->line_height/2)*draw->step; // Şu an ekranın bu pikselini boyuyorum ama texture resminin neresindeyim
}

void start_draw(t_player *ray, int x, t_mlx *mlx, t_draw_info *draw)
{
    int y;
    y = -1;
	while (++y < WIN_H)
	{
		if (y < ray->drawStart)
			put_pixel(&mlx->img, x, y, mlx->tex->floor_color);
		else if (y <= ray->drawEnd && y >= ray->drawStart)
		{
            draw->tex_y = (int)draw->texPos % draw->tex->height;
            draw->texPos += draw->step;
			put_pixel(&mlx->img, x, y, get_pixel(draw->tex, draw->tex_x, draw->tex_y));
		}
		else
			put_pixel(&mlx->img, x, y, mlx->tex->ceiling_color);
	}
}

int	ft_3d(t_mlx *mlx)
{
	int			x;
	t_player	ray;
    t_draw_info draw;

	x = -1;
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
    mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.img, 0,0);
    return 0;
}
