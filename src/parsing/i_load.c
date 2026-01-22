/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_load.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 14:57:07 by buket             #+#    #+#             */
/*   Updated: 2025/12/27 15:46:04 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	handle_tex_type(t_header *header, t_map *map, char *line, int fd)
{
	int	result;

	if (header->type == NO)
		result = load_no(header, map, line, fd);
	else if (header->type == SO)
		result = load_so(header, map, line, fd);
	else if (header->type == WE)
		result = load_we(header, map, line, fd);
	else if (header->type == EA)
		result = load_ea(header, map, line, fd);
	else
		return (-1);
	if (result == 1 && is_xpm_valid(header, header->type) == 0)
		return (2);
	return (result);
}

int	rgb_control(char *rgb)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (rgb[++i])
	{
		if (rgb[i] == ',')
			count++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	identifier_load(t_header *header, t_map *map, char *line, int fd)
{
	char	*rgb;

	if (header->type == NO || header->type == SO || header->type == WE
		|| header->type == EA)
		return (handle_tex_type(header, map, line, fd));
	else if (header->type == F || header->type == C)
	{
		rgb = ft_path_maker(line, header, map, fd);
		if (!f_c_load(header, rgb) || !rgb_control(rgb))
		{
			free(rgb);
			return (0);
		}
		free(rgb);
		return (1);
	}
	return (-1);
}
