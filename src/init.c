/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:35:12 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/09 21:25:09 by iarslan          ###   ########.fr       */
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
	return (mlx);
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
				map->player.x = x;
				map->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	map->player.planeX = 0;
	map->player.planeY = 0.66; //|dir| = 1 oldugundan dolayı |plane| = tan(fov/2)
	ft_set_orientation(map);
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
		map->player.dirY = 1;
	}
	if (map->orientation == W)
	{
		map->player.dirX = -1;
		map->player.dirY = 0;
	}
	if (map->orientation == S)
	{
		map->player.dirX = 0;
		map->player.dirY = -1;
	}
	//galiba yanlıs
}
