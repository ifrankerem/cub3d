/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:41:46 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/06 00:12:13 by iarslan          ###   ########.fr       */
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

void	cleanup_all(t_header *header, t_map *map)
{
	error_exit_header(header);
	error_map_exit(map);
}

void	error_exit_all(char *msg, t_header *header, t_map *map)
{
	cleanup_all(header, map);
	if (header)
		free(header);
	if (map)
		free(map);
	ft_putendl_fd("Error", 2);
	if (msg)
		ft_putendl_fd(msg, 2);
	exit(1);
}
