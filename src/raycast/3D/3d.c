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

// #include "cub3d.h"

// static int	rgb_to_hex(int rgb[3])
// {
// 	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
// }

// static void	convert_colors(t_header *header, t_textures *tex)
// {
// 	tex->floor_color = rgb_to_hex(header->f_rgb);
// 	tex->ceiling_color = rgb_to_hex(header->c_rgb);
// }

// static int	get_pixel(t_texture *tex, int x, int y)
// {
// 	char	*pixel;

// 	if (x < 0)
// 		x = 0;
// 	if (x >= tex->width)
// 		x = tex->width - 1;
// 	if (y < 0)
// 		y = 0;
// 	if (y >= tex->height)
// 		y = tex->height - 1;
// 	pixel = tex->addr + (y * tex->line_len + x * (tex->bpp / 8));
// 	return (*(int *)pixel);
// }

// static double	get_wall_x(t_player *ray)
// {
// }

// void	ft_3d(t_mlx *mlx, t_textures *tex, t_header *header)
// {
// 	int			x;
// 	int			y;
// 	double		wall_x;
// 	t_player	ray;
// 	t_texture	*texture;

// 	x = -1;
// 	convert_colors(header, tex);
// 	while (++x < WIN_W)
// 	{
// 		ray = mlx->map->player;
// 		ft_ray_maker(&ray, x, WIN_W);
// 		ft_dda(&ray, mlx->map);
// 		ft_wall_dist(&ray);
// 		ft_line_height(&ray, mlx->map);
// 		texture = get_texture(ray, tex);
// 		wall_x = get_wall_x(&ray);
// 		y = -1;
// 		while (++y < WIN_H)
// 		{
// 			if (y < ray.drawStart)
// 				put_pixel(&mlx->img, x, y, tex->floor_color);
// 			else if (y <= ray.drawEnd && y >= ray.drawStart)
// 			{
// 				put_pixel(&mlx->img, x, y, get_pixel(texture, x, y));
// 			}
// 			else
// 				put_pixel(&mlx->img, x, y, tex->ceiling_color);
// 		}
// 	}
// }
