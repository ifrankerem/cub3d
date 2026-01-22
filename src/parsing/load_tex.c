/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:52:54 by buket             #+#    #+#             */
/*   Updated: 2025/12/27 15:08:08 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_no(t_header *header, t_map *map, char *line, int fd)
{
	if (header->no_path)
		return (-1);
	header->no_path = ft_path_maker(line, header, map, fd);
	return (1);
}

int	load_so(t_header *header, t_map *map, char *line, int fd)
{
	if (header->so_path)
		return (-1);
	header->so_path = ft_path_maker(line, header, map, fd);
	return (1);
}

int	load_we(t_header *header, t_map *map, char *line, int fd)
{
	if (header->we_path)
		return (-1);
	header->we_path = ft_path_maker(line, header, map, fd);
	return (1);
}

int	load_ea(t_header *header, t_map *map, char *line, int fd)
{
	if (header->ea_path)
		return (-1);
	header->ea_path = ft_path_maker(line, header, map, fd);
	return (1);
}
