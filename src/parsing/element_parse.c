/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/02 00:55:11 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	header_parse(int fd, t_header *init, t_map *init_map)
{
	char	*line;
	int		i;

	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line) == 1)
		{
			while ((line = get_next_line(fd)) != NULL)
			{
				init_map->map[i] = ft_strdup(line);
				i++;
				free(line);
			}
			break ;
		}
		else
		{
			identifier_check(init, line);
			if (init->type == ERROR)
			{
				free(line);
				error_exit("Please enter identifiers correctly!!");
			}
			identifier_load(init, line);
		}
		free(line);
	}
}

static void	identifier_check(t_header *init, char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (!ft_strncmp(ptr, "NO", 2) && ft_isspace(ptr[2]))
		init->type = NO;
	else if (!ft_strncmp(ptr, "SO", 2) && ft_isspace(ptr[2]))
		init->type = SO;
	else if (!ft_strncmp(ptr, "WE", 2) && ft_isspace(ptr[2]))
		init->type = WE;
	else if (!ft_strncmp(ptr, "EA", 2) && ft_isspace(ptr[2]))
		init->type = EA;
	else if (!ft_strncmp(ptr, "F", 1) && ft_isspace(ptr[1]))
		init->type = F;
	else if (!ft_strncmp(ptr, "C", 1) && ft_isspace(ptr[1]))
		init->type = C;
	else
		init->type = ERROR;
}

static void	identifier_load(t_header *init, char *line)
{
	if (init->type == NO)
		init->no_path = ft_path_maker(line, init), " \t\n";
	else if (init->type == SO)
		init->so_path = ft_path_maker(line, init), " \t\n";
	else if (init->type == WE)
		init->we_path = ft_path_maker(line, init), " \t\n";
	else if (init->type == EA)
		init->ea_path = ft_path_maker(line, init), " \t\n";
	else if (init->type == F || init->type == C)
		f_c_load(init, ft_path_maker(line, init));
}

static void	f_c_load(t_header *init, char *ptr)
{
	int		i;
	char	**temp;
	char	*trim;

	i = 0;
	temp = ft_split(ptr, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
		error_exit("Invalid RGB format");
	while (i < 3)
	{
		trim = ft_strtrim(temp[i], " \t\n");
		if (!trim || !*trim)
			error_exit("Empty RGB value");
		if (init->type == F)
			init->f_rgb[i] = ft_atol(trim);
		else
			init->c_rgb[i] = ft_atol(trim);
		free(trim);
		if (((init->type == F) && (init->f_rgb[i] == -1)) || ((init->type == C)
				&& (init->c_rgb[i] == -1)))
			error_exit("invalid RGB");
		i++;
	}
	ft_split_free(temp);
}

int	is_map_line(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == ' ' || line[i] == 'E' || line[i] == 'W')
			flag = 1;
		else if (line[i] != ' ') // at least one valid char check!
			return (0);
		i++;
	}
	return (flag);
}
