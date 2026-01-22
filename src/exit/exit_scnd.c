/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_scnd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 13:17:24 by bucolak           #+#    #+#             */
/*   Updated: 2025/12/27 15:42:45 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	char	*line;

	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

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
