/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 01:53:47 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/04 04:00:56 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_combining(char *line, char *whole, t_map *map)
{
	char	*new;

	new = ft_strjoin(whole, line);
	if (!new)
	{
		free(whole);
		free(line);
		error_map_exit("Error\nMallocError\n", map);
	}
	free(whole);
	free(line);
	return (new);
}

void	raw_map_filler(char *line, t_map *init_map, int fd)
{
	char	*whole;

	whole = ft_strdup("");
	if (!whole)
		error_map_exit("Error\nMallocError\n", init_map);
	whole = ft_combining(line, whole, init_map); // for first line
	while ((line = get_next_line(fd)) != NULL)
		whole = ft_combining(line, whole, init_map);
	init_map->raw_map = ft_split(whole, '\n');
	free(whole);
}
