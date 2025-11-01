/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:15:14 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/02 01:26:59 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_parser(char *header, t_map *init)
{
	int fd;
	fd = open(header, O_RDONLY);
	header_parse(fd, init);
	map_parse(fd, init);
}