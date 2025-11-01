/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:14:10 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/01 00:43:51 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	header_parse(int fd, t_map *init)
{
	const char	*line;
	char		*identifier;

	while ((line = get_next_line(fd)) != NULL)
	{
		ft_memcpy(identifier, line, 2);
		if (identifier_check(identifier, init) == 1)
			return (1);
	}
}

int	identifier_check(char *identifier, t_map *init)
{
	if (ft_strncmp(identifier, "NO", 2) > 0)
	{
		init->header
		return (1);
	}

	if (ft_strncmp(identifier, "SO", 2) > 0)
		return (1);

	if (ft_strncmp(identifier, "WE", 2) > 0)
		return (1);

	if (ft_strncmp(identifier, "EA", 2) > 0)
		return (1);

	if (ft_strncmp(identifier, "F ", 2) > 0)
		return (1);

	if (ft_strncmp(identifier, "C ", 2) > 0)
		return (1);
}