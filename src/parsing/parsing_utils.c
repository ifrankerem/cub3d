/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:28:54 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/30 14:11:04 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

static void	ft_path_maker_helper(t_header *init, char **end)
{
	if (init->type == F || init->type == C)
	{
		while (**end && **end != '\n')
			(*end)++;
		return ;
	}
	while (**end && !ft_isspace(**end) && **end != '\n')
		(*end)++;
	while (ft_isspace(**end))
		(*end)++;
}

char	*ft_path_maker(char *line, t_header *init, t_map *map, int fd)
{
	char	*ptr;
	char	*start;
	char	*end;
	char	*path;

	init->flag++;
	ptr = line;
	while (ft_isspace(*ptr))
		ptr++;
	ptr += 2;
	while (ft_isspace(*ptr))
		ptr++;
	start = ptr;
	end = start;
	ft_path_maker_helper(init, &end);
	if (init->type == F || init->type == C)
		return (ft_substr(start, 0, end - start));
	if (*end != '\0' && *end != '\n')
	{
		free(line);
		cleanup_gnl(fd);
		error_exit_all("Extra tokens in path line!", init, map, NULL);
	}
	path = ft_substr(start, 0, end - start);
	return (path);
}

int	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	number;

	number = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		number = number * 10 + (nptr[i] - 48);
		i++;
	}
	if (number * sign > 255 || number * sign < 0 || nptr[i] != '\0')
		return (-1);
	return (number * sign);
}

void	*ft_grid_maker(size_t count, size_t size, t_map *init_map,
		t_header *header)
{
	void			*x;
	unsigned char	*str;
	size_t			i;

	i = 0;
	x = malloc(count * (size + 1));
	if (x == NULL)
		error_exit_all("Malloc Error", header, init_map, NULL);
	str = (unsigned char *)x;
	while (i < (count * size))
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
