/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:19 by buket             #+#    #+#             */
/*   Updated: 2025/11/29 15:02:45 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int process_rgb(t_header *header, char **temp, int i)
{
	char *trim;
	
	trim = ft_strtrim(temp[i], " \t\n");
	if (!trim || !*trim)
	{
		free(trim);
		return (0);
	}
	if (header->type == F)
		header->f_rgb[i] = ft_atol(trim);
	else
		header->c_rgb[i] = ft_atol(trim);
	free(trim);
	if (((header->type == F) && (header->f_rgb[i] == -1))
		|| ((header->type == C) && (header->c_rgb[i] == -1)))
		return (0);
	return 1;
}

int	f_c_load(t_header *header, char *ptr)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(ptr, ',');
	if (!temp || !temp[0] || !temp[1] || !temp[2] || temp[3])
	{
		free_2d_array(temp);
		return (0);
	}
	while (i < 3)
	{
		if(!process_rgb(header, temp, i))
		{
			free_2d_array(temp);
			return 0;
		}
		i++;
	}
	free_2d_array(temp);
	return (1);
}
