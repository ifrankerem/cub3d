/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:46:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/04 04:26:28 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_header	*init;
	t_map		*map;

	if (argc != 2)
		return (printf("Error\nInvalid Program Use!\n"), 1);
	init = malloc(sizeof(*init));
	if (!init)
		return (free(init), printf("Error\nMallocError\n"), 1);
	map = malloc(sizeof(*map));
	if (!map)
		return (free(map), printf("Error\nMallocError\n"), 1);
	main_parser(argv[1], init, map);
	debug(map, init);
	free(map);
	free(init);
}
