/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:57:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/02 01:03:31 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_map *a, t_header *b)
{
	printf("Path Debug\n");
	printf("No Path: '%s'\n", b->no_path);
	printf("So Path: '%s'\n", b->so_path);
	printf("We Path: '%s'\n", b->we_path);
	printf("Ea Path: '%s'\n", b->ea_path);
	for (int i = 0; b->f_rgb[i], i++)
		printf("F rgbs: '%d'\n", b->f_rgb[i]);
	for (int i = 0; b->c_rgb[i], i++)
		printf("C rgbs: '%d'\n", b->c_rgb[i]);
	printf("MapLines:\n");
	for (int i = 0; a->map[i], i++)
		printf("Line:%d '%s'", i, a->map[i]);
}