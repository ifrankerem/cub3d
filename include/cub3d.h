/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/09 21:03:47 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h> // for keysym!!
# include <fcntl.h>      // for open() read()
# include <math.h>
# include <stdio.h> // for printf
# include <stdlib.h>
# include <unistd.h>

# define WIN_W 1280
# define WIN_H 720

enum			TYPE
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	ERROR,
};

enum			ORIENTATION
{
	N,
	S,
	W,
	E,
};

enum			KEY
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
};

typedef struct s_header
{
	int			type;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	int			f_rgb[3];
	int			c_rgb[3];
	int			flag;

}				t_header;

// for 2D DEBUG AND LEARNING

typedef struct s_img
{
	void *img;    // MLX image pointer (handle)
	char *addr;   // bellekteki piksel adresi
	int bpp;      // bits per pixel
	int line_len; // bir satırın byte uzunluğu
	int endian;   // sistem endian tipi
}				t_img;

typedef struct s_player
{
	int			x;
	int			y;
	double dirX;   // oyuncunun baktığı yön
	double dirY;   // oyuncunun baktığı yön
	double planeX; // FOV
	double planeY; // FOV
}				t_player;

typedef struct s_map
{
	char		**raw_map;
	char		**grid;
	int			orientation;
	int			height;
	int			width;
	t_player	player;
}				t_map;

typedef struct s_mlx
{
	void		*win;
	void		*ptr;
	t_img		img;
	t_map		*map;
	t_header	*header;

}				t_mlx;

// FOR DEBUG DELETE BEFORE EVAL
void			debug(t_map *m, t_header *h);

// Main
void			main_parser(char *header, t_header *init, t_map *map);
void			header_parse(int fd, t_header *init, t_map *init_map);
void			map_parse(t_map *map, t_header *header);
// init

t_header		*init_header(void);
t_map			*init_map(void);
t_mlx			*ft_mlx_init(t_map *map, t_header *header);
void			player_init(t_map *map);

// Utils
int				ft_isspace(char c);
void			ft_split_free(char **temp);
char			*ft_path_maker(char *line, t_header *init, t_map *map);
int				ft_atol(const char *nptr);
void			*ft_grid_maker(size_t count, size_t size, t_map *init_map,
					t_header *header);
char			*ft_combining(char *line, char *whole, t_map *map,
					t_header *header);
void			raw_map_filler(char *line, t_map *init_map, int fd,
					t_header *header);

// Flood Fill
void			fill_space(char **cpy_map, int x, int y, t_map *map);
void			flood_fill_for_space(char **cpy_map, t_map *map);
char			**make_copy(t_map *map, t_header *header);
void			copy_mapcontrol_space(t_map *map, char **cpy_map,
					t_header *header);
void			free_cpymap(char **cpy_map);

// MLX
void			open_window(t_mlx *mlx, t_map *map, t_header *header);
int				close_window(t_mlx *mlx);
int				movement_and_exit(int keysym, t_mlx *mlx);
void			player_move(t_player *player, int key);

// 2D Rendering
void			ft_2d_init(t_mlx *mlx);
void			put_pixel(t_img *img, int x, int y, int color);
void			draw_square(t_img *img, int x, int y, int size, int color);
void			draw_map(t_mlx *mlx, int tile_size);
void			draw_player(t_mlx *mlx, int tile_size);
int				draw_loop(t_mlx *mlx);

// void		close_window(void);
//
void			error_map_exit(t_map *init_map);
void			error_exit_header(t_header *init);
void			cleanup_all(t_header *header, t_map *map);
void			free_2d_array(char **array);
void			error_exit_all(char *msg, t_header *header, t_map *map);

#endif