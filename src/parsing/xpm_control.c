/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 12:02:30 by bucolak           #+#    #+#             */
/*   Updated: 2025/12/27 15:53:14 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	control_so(t_header *header)
{
	int		i;
	int		end;
	char	*old_so_path;

	i = 0;
	while (header->so_path[i] && ft_isspace(header->so_path[i]) == 0)
		i++;
	end = i - 1;
	old_so_path = header->so_path;
	header->so_path = ft_strtrim(header->so_path, " \t\r\v\f");
	free(old_so_path);
	if (end < 3 || header->so_path[end] != 'm'
		|| header->so_path[end - 1] != 'p'
		|| header->so_path[end - 2] != 'x'
		|| header->so_path[end - 3] != '.')
		return (0);
	return (1);
}

static int	control_we(t_header *header)
{
	int		i;
	int		end;
	char	*old_we_path;

	i = 0;
	while (header->we_path[i] && ft_isspace(header->we_path[i]) == 0)
		i++;
	end = i - 1;
	old_we_path = header->we_path;
	header->we_path = ft_strtrim(header->we_path, " \t\r\v\f");
	free(old_we_path);
	if (end < 4 || header->we_path[end] != 'm'
		|| header->we_path[end - 1] != 'p'
		|| header->we_path[end - 2] != 'x'
		|| header->we_path[end - 3] != '.')
		return (0);
	return (1);
}

static int	control_no(t_header *header)
{
	int		i;
	int		end;
	char	*old_no_path;

	i = 0;
	while (header->no_path[i] && ft_isspace(header->no_path[i]) == 0)
		i++;
	end = i - 1;
	old_no_path = header->no_path;
	header->no_path = ft_strtrim(header->no_path, " \t\r\v\f");
	free(old_no_path);
	if (end < 4 || header->no_path[end] != 'm'
		|| header->no_path[end - 1] != 'p'
		|| header->no_path[end - 2] != 'x'
		|| header->no_path[end - 3] != '.')
		return (0);
	return (1);
}

static int	control_ea(t_header *header)
{
	int		i;
	int		end;
	char	*old_ea_path;

	i = 0;
	while (header->ea_path[i] && ft_isspace(header->ea_path[i]) == 0)
		i++;
	end = i - 1;
	old_ea_path = header->ea_path;
	header->ea_path = ft_strtrim(header->ea_path, " \t\r\v\f");
	free(old_ea_path);
	if (end < 3 || header->ea_path[end] != 'm'
		|| header->ea_path[end - 1] != 'p'
		|| header->ea_path[end - 2] != 'x'
		|| header->ea_path[end - 3] != '.')
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
