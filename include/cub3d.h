/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/02 01:01:23 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h> // for open() read()
# include <math.h>
# include <stdio.h> // for printf
# include <stdlib.h>
# include <unistd.h>

enum		TYPE
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR,
};

typedef struct s_header
{
	int		type;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*f_rgb[3];
	int		*c_rgb[3];
	
}			t_header;

typedef struct s_map
{
	char	**map;
	char	orientation;
}			t_map;

#endif