/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:35:12 by iarslan           #+#    #+#             */
/*   Updated: 2025/12/27 15:23:53 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_draw(t_draw_info *draw)
{
	draw->step = 0;
	draw->tex_x = 0;
	draw->tex_y = 0;
	draw->tex_pos = 0;
	draw->tex = NULL;
}

t_header	*init_header(void)
{
	t_header	*header;

	header = malloc(sizeof(t_header));
	if (!header)
	{
		ft_putendl_fd("Error: Memory allocation failed for header", 2);
		return (NULL);
	}
	ft_bzero(header, sizeof(*header));
	header->c_rgb[0] = -1;
	header->c_rgb[1] = -1;
	header->c_rgb[2] = -1;
	header->f_rgb[0] = -1;
	header->f_rgb[1] = -1;
	header->f_rgb[2] = -1;
	header->type = -1;
	return (header);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
	{
		ft_putendl_fd("Error: Memory allocation failed for map", 2);
		return (NULL);
	}
	ft_bzero(map, sizeof(*map));
	map->orientation = -1;
	map->player.x = -1;
	map->player.y = -1;
	return (map);
}

void	ft_texture_init(t_mlx *mlx, t_textures *tex)
{
	tex->north.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->no_path,
			&tex->north.width, &tex->north.height);
	img_control(tex->north.img, mlx);
	tex->north.addr = mlx_get_data_addr(tex->north.img, &tex->north.bpp,
			&tex->north.line_len, &tex->north.endian);
	tex->south.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->so_path,
			&tex->south.width, &tex->south.height);
	img_control(tex->south.img, mlx);
	tex->south.addr = mlx_get_data_addr(tex->south.img, &tex->south.bpp,
			&tex->south.line_len, &tex->south.endian);
	tex->east.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->ea_path,
			&tex->east.width, &tex->east.height);
	img_control(tex->east.img, mlx);
	tex->east.addr = mlx_get_data_addr(tex->east.img, &tex->east.bpp,
			&tex->east.line_len, &tex->east.endian);
	tex->west.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->we_path,
			&tex->west.width, &tex->west.height);
	img_control(tex->west.img, mlx);
	tex->west.addr = mlx_get_data_addr(tex->west.img, &tex->west.bpp,
			&tex->west.line_len, &tex->west.endian);
}

t_mlx	*ft_mlx_init(t_map *map, t_header *header, t_textures *tex)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		ft_putendl_fd("Error: Memory allocation failed for mlx", 2);
		return (NULL);
	}
	ft_bzero(mlx, sizeof(*mlx));
	mlx->ptr = mlx_init();
	mlx->win = NULL;
	mlx->map = map;
	mlx->header = header;
	mlx->tex = tex;
	mlx->keys.w = 0;
	mlx->keys.a = 0;
	mlx->keys.s = 0;
	mlx->keys.d = 0;
	mlx->keys.right = 0;
	mlx->keys.left = 0;
	return (mlx);
}
