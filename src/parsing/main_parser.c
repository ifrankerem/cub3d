/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/04 00:01:38 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_parser(char *header, t_header *init, t_map *map)
{
	int	fd;

	fd = open(header, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nInvalid file name!\n"), exit(1));
	header_parse(fd, init, map);
	map_parse(map);
}
