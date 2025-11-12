/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:35:12 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/13 01:16:44 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:29:34 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/06 15:35:25 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_mlx	*ft_mlx_init(t_map *map, t_header *header)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
	{
		ft_putendl_fd("Error: Memory allocation failed for mlx", 2);
		return (NULL);
	}
	ft_bzero(mlx, sizeof(*mlx));
	mlx->map = map;
	mlx->header = header;
	mlx->keys.w = 0;
	mlx->keys.a = 0;
	mlx->keys.s = 0;
	mlx->keys.d = 0;
	return (mlx);
}

static void	ft_set_orientation(t_map *map)
{
	if (map->orientation == E)
	{
		map->player.dirX = 1;
		map->player.dirY = 0;
	}
	if (map->orientation == N)
	{
		map->player.dirX = 0;
		map->player.dirY = -1;
	}
	if (map->orientation == W)
	{
		map->player.dirX = -1;
		map->player.dirY = 0;
	}
	if (map->orientation == S)
	{
		map->player.dirX = 0;
		map->player.dirY = +1;
	}
}

static void	ft_set_plane(t_map *map)
{
	double	plane_length;

	plane_length = tan(FOV_DEG * M_PI / 180.0 / 2);
	if (map->orientation == E)
	{
		map->player.planeX = 0;
		map->player.planeY = -plane_length;
	}
	if (map->orientation == N)
	{
		map->player.planeX = plane_length;
		map->player.planeY = 0;
	}
	if (map->orientation == W)
	{
		map->player.planeX = 0;
		map->player.planeY = plane_length;
	}
	if (map->orientation == S)
	{
		map->player.planeX = -plane_length;
		map->player.planeY = 0;
	}
}

static void	player_init_2(t_player *player)
{
	player->perpWallDist = 0;
	player->sideDistX = 0;
	player->sideDistY = 0;
	player->wall_hit = 0;
	player->deltaDistX = fabs(1 / player->rayDirX);
	player->deltaDistY = fabs(1 / player->rayDirY);
}
void	player_init(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'E' || map->grid[y][x] == 'W')
			{
				map->player.x = x + 0.5;
				map->player.y = y + 0.5;
				ft_set_orientation(map);
				ft_set_plane(map);
				return ;
			}
			x++;
		}
		y++;
	}
	player_init_2(&map->player);
}

void	ft_texture_init(t_mlx *mlx, t_textures *tex)
{
	// north
	tex->north.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->no_path,
			&tex->north.width, &tex->north.height);
	tex->north.addr = mlx_get_data_addr(tex->north.img, &tex->north.bpp,
			&tex->north.line_len, &tex->north.endian);
	// south
	tex->south.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->so_path,
			&tex->south.width, &tex->south.height);
	tex->south.addr = mlx_get_data_addr(tex->south.img, &tex->south.bpp,
			&tex->south.line_len, &tex->south.endian);
	// east
	tex->east.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->ea_path,
			&tex->east.width, &tex->east.height);
	tex->east.addr = mlx_get_data_addr(tex->east.img, &tex->east.bpp,
			&tex->east.line_len, &tex->east.endian);
	// west
	tex->west.img = mlx_xpm_file_to_image(mlx->ptr, mlx->header->we_path,
			&tex->west.width, &tex->west.height);
	tex->west.addr = mlx_get_data_addr(tex->west.img, &tex->west.bpp,
			&tex->west.line_len, &tex->west.endian);
}