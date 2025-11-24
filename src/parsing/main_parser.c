/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/24 21:47:04 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_raw_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->raw_map[i])
	{
		printf("%s", map->raw_map[i]);
		i++;
	}
}

void	file_name_control(char *header_map, t_map *map, t_header *header)
{
	int	i;
	int	end;

	i = 0;
	while (header_map[i])
		i++;
	end = i - 1;
	if ((end - 4) > 0 && header_map[end] == 'b' && header_map[end - 1] == 'u'
		&& header_map[end - 2] == 'c' && header_map[end - 3] == '.')
		return ;
	error_exit_all("Wrong file name!", header, map);
}

void	main_parser(char *header, t_header *init, t_map *map)
{
	int	fd;

	fd = open(header, O_RDONLY);
	if (fd == -1)
		error_exit_all("Invalid file name!", init, map); // bu mesaj fd ile değiştirilse nasıl olur? wrong file name mesajıyla karışmaması açısından
	file_name_control(header, map, init);
	header_parse(fd, init, map);
	// print_raw_map(map);
	if(!map->raw_map)
		error_exit_all("No Map!", init, map);
	//print_raw_map(map);
	map_parse(map, init);
}
