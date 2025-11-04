/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:28:54 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/04 02:38:50 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "limits.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}
void	ft_split_free(char **temp)
{
	int	i;

	i = 0;
	if (!temp)
		return ;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

char	*ft_path_maker(char *line, t_header *init)
{
	char	*ptr;
	char	*start;
	char	*end;
	char	*path;

	ptr = line;
	while (ft_isspace(*ptr))
		ptr++;
	ptr += 2;
	while (ft_isspace(*ptr))
		ptr++;
	if (init->type == F || init->type == C)
		return (ptr);
	start = ptr;
	end = start;
	while (*end && !ft_isspace(*end) && *end != '\n')
		end++;
	while (ft_isspace(*end))
		end++;
	if (*end != '\0' && *end != '\n')
		error_exit_header("Error\nExtra tokens in path line!!\n", init);
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

void	*ft_grid_maker(size_t count, size_t size, t_map *init_map)
{
	void			*x;
	unsigned char	*str;
	size_t			i;

	i = 0;
	x = malloc(count * size);
	if (x == NULL)
		error_map_exit("Error\nMalloc Error\n,", init_map);
	str = (unsigned char *)x;
	while (i < (count * size))
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}
