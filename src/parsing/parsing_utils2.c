/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:53:47 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/29 15:04:46 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_combining(char *line, char *whole, t_map *map, t_header *header)
{
	char	*new;

	new = ft_strjoin(whole, line);
	if (!new)
	{
		free(whole);
		free(line);
		error_exit_all("Malloc Error", header, map, NULL);
	}
	free(whole);
	free(line);
	return (new);
}

void	fill_m(char *whole, t_map *map)
{
	int	i;
	int	c;
	int	start;

	i = -1;
	c = 0;
	while (whole[++i])
	{
		if (whole[i] == '\n')
			c++;
	}
	map->raw_map = malloc(sizeof(char *) * (c + 2));
	i = 0;
	c = 0;
	while (whole[i])
	{
		start = i;
		while (whole[i] && whole[i] != '\n')
			i++;
		map->raw_map[c++] = ft_substr(whole, start, i - start);
		if (whole[i] == '\n')
			i++;
	}
	map->raw_map[c] = NULL;
}

void	raw_map_filler(char *line, t_map *init_map, int fd, t_header *header)
{
	char	*whole;

	whole = ft_strdup("");
	if (!whole)
		error_exit_all("Malloc Error", header, init_map, NULL);
	whole = ft_combining(line, whole, init_map, header);
	while ((line = get_next_line(fd)) != NULL)
		whole = ft_combining(line, whole, init_map, header);
	// init_map->raw_map = ft_split(whole, '\n');
	fill_m(whole, init_map);
	free(whole);
}

int	is_map_started(char *line)
{
	int	i;
	int	verify_map;

	verify_map = 1;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!(line[i] == '0' || line[i] == '1' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
				|| line[i] == ' '))
			verify_map = 0;
		;
		i++;
	}
	return (verify_map);
}
