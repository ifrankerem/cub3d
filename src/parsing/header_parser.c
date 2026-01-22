/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/12/27 15:46:04 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	identifier_check(t_header *header, char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (!ft_strncmp(ptr, "NO", 2) && ft_isspace(ptr[2]))
		header->type = NO;
	else if (!ft_strncmp(ptr, "SO", 2) && ft_isspace(ptr[2]))
		header->type = SO;
	else if (!ft_strncmp(ptr, "WE", 2) && ft_isspace(ptr[2]))
		header->type = WE;
	else if (!ft_strncmp(ptr, "EA", 2) && ft_isspace(ptr[2]))
		header->type = EA;
	else if (!ft_strncmp(ptr, "F", 1) && ft_isspace(ptr[1]))
		header->type = F;
	else if (!ft_strncmp(ptr, "C", 1) && ft_isspace(ptr[1]))
		header->type = C;
	else
	{
		header->type = ERROR;
	}
}

static void	load_and_result(int fd, t_header *header, t_map *map, char *line)
{
	int	id_load;

	id_load = identifier_load(header, map, line, fd);
	if (id_load == 0)
	{
		free(line);
		cleanup_gnl(fd);
		error_exit_all("Invalid RGB!", header, map, NULL);
	}
	else if (id_load == -1)
	{
		free(line);
		cleanup_gnl(fd);
		error_exit_all("Please enter identifiers correctly!", header, map,
			NULL);
	}
	else if (id_load == 2)
	{
		free(line);
		cleanup_gnl(fd);
		error_exit_all("Wrong XPM Format!", header, map, NULL);
	}
}

static void	handle_identifier_check(int fd, t_header *header, t_map *map,
		char *line)
{
	identifier_check(header, line);
	if (header->type == ERROR)
	{
		free(line);
		cleanup_gnl(fd);
		error_exit_all("Please enter identifiers correctly!", header, map,
			NULL);
	}
}

static void	process_line(int fd, t_header *header, t_map *map, char *line)
{
	if (header->ea_path && header->we_path && header->so_path
		&& header->no_path && is_map_started(line) == 1)
	{
		if (header->flag == 6)
		{
			raw_map_filler(line, map, fd, header);
			return ;
		}
		free(line);
		cleanup_gnl(fd);
		error_exit_all("Please enter identifiers correctly!", header, map,
			NULL);
	}
	else
	{
		handle_identifier_check(fd, header, map, line);
		load_and_result(fd, header, map, line);
	}
	free(line);
}

void	header_parse(int fd, t_header *header, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		error_exit_all("Empty Map!", header, map, NULL);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		process_line(fd, header, map, line);
		if (header->ea_path && header->we_path && header->so_path
			&& header->no_path && map->raw_map)
			break ;
		line = get_next_line(fd);
	}
}
