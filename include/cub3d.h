/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/04 04:25:00 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
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

enum		ORIENTATION
{
	N,
	S,
	W,
	E,
};

typedef struct s_header
{
	int		type;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		f_rgb[3];
	int		c_rgb[3];
	int		flag;

}			t_header;

typedef struct s_map
{
	char	**raw_map;
	char	**grid;
	int		orientation;
	int		height;
	int		width;
}			t_map;

// FOR DEBUG DELETE BEFORE EVAL
void		debug(const t_map *m, const t_header *h);

// Main
void		main_parser(char *header, t_header *init, t_map *map);
void		header_parse(int fd, t_header *init, t_map *init_map);
void		map_parse(t_map *map);
// Utils
int			ft_isspace(char c);
void		ft_split_free(char **temp);
char		*ft_path_maker(char *line, t_header *init);
int			ft_atol(const char *nptr);
void		*ft_grid_maker(size_t count, size_t size, t_map *init_map);
char		*ft_combining(char *line, char *whole, t_map *map);
void		raw_map_filler(char *line, t_map *init_map, int fd);

// Flood Fill
void		fill_space(char **cpy_map, int x, int y, t_map *map);
void		flood_fill_for_space(char **cpy_map, t_map *map);
char		**make_copy(t_map *map);
void		copy_mapcontrol_space(t_map *map, char **cpy_map);
void		free_cpymap(char **cpy_map);
// Exit
void		error_exit_header(char *error_message, t_header *init);
void		error_map_exit(char *error_message, t_map *init_map);

#endif