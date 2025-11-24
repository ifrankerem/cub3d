/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/24 22:21:54 by buket            ###   ########.fr       */
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

static void	f_c_load(t_header *header, t_map *map, char *ptr)
{
	int		i;
	char	**temp;
	char	*trim;

	i = 0;
	temp = ft_split(ptr, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
	{
		free_2d_array(temp);
		error_exit_all("Invalid RGB format", header, map);
	}
	while (i < 3)
	{
		trim = ft_strtrim(temp[i], " \t\n");
		if (!trim || !*trim)
			error_exit_all("Empty RGB value", header, map);
		if (header->type == F)
			header->f_rgb[i] = ft_atol(trim);
		else
			header->c_rgb[i] = ft_atol(trim);
		free(trim);
		if (((header->type == F) && (header->f_rgb[i] == -1))
			|| ((header->type == C) && (header->c_rgb[i] == -1)))
			error_exit_all("Invalid RGB", header, map);
		i++;
	}
	free_2d_array(temp);
}

static void	identifier_load(t_header *header, t_map *map, char *line)
{
	if (header->type == NO)
	{
		header->no_path = ft_path_maker(line, header, map);
	}
	else if (header->type == SO)
	{
		header->so_path = ft_path_maker(line, header, map);
	}
	else if (header->type == WE)
	{
		header->we_path = ft_path_maker(line, header, map);
	}
	else if (header->type == EA)
	{
		header->ea_path = ft_path_maker(line, header, map);
	}
	else if (header->type == F || header->type == C)
	{
		f_c_load(header, map, ft_path_maker(line, header, map));
	}
	is_xpm_valid(map, header, header->type);
}

static int	is_map_started(char *line)
{
	int	i;
	int verify_map;

	verify_map = 1;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' '))
			verify_map = 0;;
		i++;
	}
	return (verify_map);
}

void	header_parse(int fd, t_header *header, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if(!line)
		error_exit_all("Empty Map!", header, map);
	while (line)
	{
		if (line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		if (header->ea_path && header->we_path && header->so_path 
			&& header->no_path && is_map_started(line) == 1)
		{
			if (header->flag == 6) // Map başladı mı?
			{
				raw_map_filler(line, map, fd, header);
				break ;
			}
			else
			{ // Flag 6 ama hala map başlamadı
				free(line);
				error_exit_all("Please enter identifiers correctly!", header,
					map);
			}
		}
		else
		{
			identifier_check(header, line);
			if (header->type == ERROR)
			{
				free(line);
				error_exit_all("Please enter identifiers correctly!", header,
					map);
			}
			identifier_load(header, map, line);
		}
		free(line);
		line = get_next_line(fd);
	}
}
