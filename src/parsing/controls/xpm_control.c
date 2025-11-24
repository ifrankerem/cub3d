/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:02:30 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/24 21:26:04 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

static void	control_so(t_map *map, t_header *header)
{
	int	i;
	int	end;

	i = 0;
	while (header->so_path[i])
		i++;
	end = i - 1;
	if (end < 3 || header->so_path[end] != 'm' || header->so_path[end
		- 1] != 'p' || header->so_path[end - 2] != 'x' || header->so_path[end
		- 3] != '.')
		error_exit_all("Wrong XPM Format!", header, map);
}

static void control_we(t_map *map, t_header *header)
{
	int	i;
	int	end;

	i = 0;
	while (header->we_path[i])
		i++;
	end = i - 1;
	if (end < 3 || header->we_path[end] != 'm' || header->we_path[end
		- 1] != 'p' || header->we_path[end - 2] != 'x' || header->we_path[end
		- 3] != '.')
		error_exit_all("Wrong XPM Format!", header, map);
}

static void	control_no(t_map *map, t_header *header)
{
	int	i;
	int	end;

	i = 0;
	while (header->no_path[i])
		i++;
	end = i - 1;
	if (end < 3 || header->no_path[end] != 'm' || header->no_path[end
		- 1] != 'p' || header->no_path[end - 2] != 'x' || header->no_path[end
		- 3] != '.')
			error_exit_all("Wrong XPM Format!", header, map);
}

static void control_ea(t_map *map, t_header *header)
{
	int i;
	int	end;
	
	i = 0;
	while (header->ea_path[i])
		i++;
	end = i - 1;
	if (end < 3 || header->ea_path[end] != 'm' || header->ea_path[end
		- 1] != 'p' || header->ea_path[end - 2] != 'x' || header->ea_path[end
		- 3] != '.')
		error_exit_all("Wrong XPM Format!", header, map);
}

void	is_xpm_valid(t_map *map, t_header *header, int type)
{
	if(type == NO)
		control_no(map, header);
	else if(type == SO)
		control_so(map, header);
	else if(type == WE)
		control_we(map, header);
	else if(type == EA)
		control_ea(map, header);
}
