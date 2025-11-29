/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:02:30 by bucolak           #+#    #+#             */
/*   Updated: 2025/11/29 16:10:17 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	control_so(t_header *header)
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
		return (0);
	return (1);
}

static int	control_we(t_header *header)
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
		return (0);
	return (1);
}

static int	control_no(t_header *header)
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
		return (0);
	return (1);
}

static int	control_ea(t_header *header)
{
	int	i;
	int	end;

	i = 0;
	while (header->ea_path[i])
		i++;
	end = i - 1;
	if (end < 3 || header->ea_path[end] != 'm' || header->ea_path[end
		- 1] != 'p' || header->ea_path[end - 2] != 'x' || header->ea_path[end
		- 3] != '.')
		return (0);
	return (1);
}

int	is_xpm_valid(t_header *header, int type)
{
	if (type == NO)
		return (control_no(header));
	else if (type == SO)
		return (control_so(header));
	else if (type == WE)
		return (control_we(header));
	else if (type == EA)
		return (control_ea(header));
	return (1);
}
