/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:41:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/27 18:33:21 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	error_exit_header(t_header *init)
{
	if (init->ea_path)
		free(init->ea_path);
	if (init->no_path)
		free(init->no_path);
	if (init->so_path)
		free(init->so_path);
	if (init->we_path)
		free(init->we_path);
}

void	error_map_exit(t_map *init_map)
{
	if (!init_map)
		return ;
	if (init_map->raw_map)
		free_2d_array(init_map->raw_map);
	if (init_map->grid)
		free_2d_array(init_map->grid);
}

void	clean_textures(t_mlx *mlx)
{
	if (mlx->tex)
	{
		if (mlx->tex->east.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->east.img);
		if (mlx->tex->north.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->north.img);
		if (mlx->tex->south.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->south.img);
		if (mlx->tex->west.img)
			mlx_destroy_image(mlx->ptr, mlx->tex->west.img);
	}
}

void	clean_mlx_func(t_mlx *mlx)
{
	if (mlx->img.img)
		mlx_destroy_image(mlx->ptr, mlx->img.img);
	if (mlx->win)
		mlx_destroy_window(mlx->ptr, mlx->win);
	if (mlx->ptr)
	{
		mlx_destroy_display(mlx->ptr);
		free(mlx->ptr);
	}
	if (mlx)
		free(mlx);
}
void	cleanup_all(t_header *header, t_map *map, t_mlx *mlx)
{
	if (header)
		error_exit_header(header);
	if (map)
		error_map_exit(map);
	if (mlx)
		clean_textures(mlx);
	if (mlx)
		clean_mlx_func(mlx);
	if (header)
		free(header);
	if (map)
		free(map);
}
void	error_exit_all(char *msg, t_header *header, t_map *map, t_mlx *mlx)
{
	cleanup_all(header, map, mlx);
	ft_putendl_fd("Error", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}

void	cleanup_gnl(int fd)
{
	char *line;
	if (fd < 0)
		return ;
	while ((line = get_next_line(fd)))
		free(line);
}