/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:46:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/06 02:27:37 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_header	*header;
	t_map		*map;

	if (argc != 2)
		return (ft_putendl_fd("Error\nInvalid Program Use!", 2), 1);
	header = malloc(sizeof(*header));
	if (!header)
		error_exit_all("Malloc Error", NULL, NULL);
	ft_bzero(header, sizeof(*header));
	map = malloc(sizeof(*map));
	if (!map)
		error_exit_all("Malloc Error", header, NULL);
	ft_bzero(map, sizeof(*map));
	main_parser(argv[1], header, map);
	debug(map, header);
	cleanup_all(header, map);
	return (0);
}
