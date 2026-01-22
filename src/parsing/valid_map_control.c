/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:14:29 by buket             #+#    #+#             */
/*   Updated: 2025/11/29 15:14:45 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	is_chars_valid(t_map *map, t_header *header)
{
	int	i;
	int	j;
	int	p_count;

	p_count = 0;
	i = -1;
	while (map->raw_map[++i])
	{
		j = -1;
		while (map->raw_map[i][++j])
		{
			if (!(map->raw_map[i][j] == '0' || map->raw_map[i][j] == '1'
					|| map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
					|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W'
					|| map->raw_map[i][j] == ' '))
				error_exit_all("Invalid Chars in MAP!", header, map, NULL);
			else if (map->raw_map[i][j] == 'N' || map->raw_map[i][j] == 'S'
				|| map->raw_map[i][j] == 'E' || map->raw_map[i][j] == 'W')
				p_count++;
		}
	}
	if (p_count > 1)
		error_exit_all("Multiple player spawns", header, map, NULL);
	else if (p_count == 0)
		error_exit_all("There is no Player", header, map, NULL);
}

void	is_empty_line(t_map *map, t_header *header)
{
	int	i;
	int	flag;
	int	len;

	i = -1;
	flag = 0;
	len = -1;
	while (map->raw_map[++i])
	{
		len = ft_strlen(map->raw_map[i]);
		if (flag == 1 && len > 0)
			error_exit_all("Extra char in the MAP!", header, map, NULL);
		if (len == 0)
		{
			flag = 1;
			continue ;
		}
	}
}
