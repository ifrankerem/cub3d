/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 00:57:00 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/06 01:27:02 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_map *m, t_header *h)
{
	int	y;

	if (!m || !h)
	{
		fprintf(stderr, "debug: null ptr\n");
		return ;
	}
	printf("== Path Debug ==\n");
	printf("NO: %s\n", h->no_path ? h->no_path : "(null)");
	printf("SO: %s\n", h->so_path ? h->so_path : "(null)");
	printf("WE: %s\n", h->we_path ? h->we_path : "(null)");
	printf("EA: %s\n", h->ea_path ? h->ea_path : "(null)");
	printf("F rgb: {%d, %d, %d}\n", h->f_rgb[0], h->f_rgb[1], h->f_rgb[2]);
	printf("C rgb: {%d, %d, %d}\n", h->c_rgb[0], h->c_rgb[1], h->c_rgb[2]);
	printf("\n== Raw Map ==\n");
	if (m->raw_map)
	{
		y = -1;
		while (m->raw_map[++y])
			printf("[%02d] \"%s\"\n", y, m->raw_map[y] ? m->raw_map[y] : "");
	}
	printf("\n== Grid (H=%d, W=%d) ==\n", m->height, m->width);
	if (m->grid)
	{
		for (int y = 0; y < m->height; y++)
			printf("[%02d] \"%s\"\n", y, m->grid[y] ? m->grid[y] : "");
	}
	fflush(stdout);
}
