/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/26 17:19:33 by buket            ###   ########.fr       */
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
#include <sys/time.h>

# define WIN_W 1920
# define WIN_H 1080
# define FOV_DEG 66.0
# define M_PI 3.14159265358979323846
// # define ROT_SPEED 0.05
// # define MOVE_SPEED 0.05

enum			TYPE
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	NL,
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

typedef struct s_texture
{
	void *img;  // MLX image pointer
	char *addr; // Piksel verisi
	int width;  // Bu texture'ın genişliği
	int height; // Bu texture'ın yüksekliği
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

typedef struct s_textures
{
	t_texture north;   // Kuzey texture'ı (tüm bilgisiyle)
	t_texture south;   // Güney texture'ı (tüm bilgisiyle)
	t_texture west;    // Batı texture'ı (tüm bilgisiyle)
	t_texture east;    // Doğu texture'ı (tüm bilgisiyle)
	int floor_color;   // RGB format: 0xRRGGBB
	int ceiling_color; // RGB format: 0xRRGGBB
}				t_textures;

typedef struct s_draw_info
{
	t_texture	*tex;
	double		step;
	double		texPos;
	int			tex_x;
	int			tex_y;
}				t_draw_info;

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
	double		x;
	double		y;
	long long time;
	double move_speed;
	double rot_speed;
	double dirX;   // oyuncunun baktığı yön
	double dirY;   // oyuncunun baktığı yön
	double planeX; // oyuncu plane (aslında kendisi gibi bişi)
	double planeY; // oyuncu plane (aslında kendisi gibi bişi)
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			line_height;
	int			drawStart;
	int			drawEnd;
	int			wall_hit;
	int			side;

}				t_player;

typedef struct s_map
{
	char		**raw_map;
	char		**grid;
	int			orientation;
	int			height;
	int			width;
	t_player	player;
	t_texture	textures;
}				t_map;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int right;
	int left;
}				t_keys;

typedef struct s_mlx
{
	void		*win;
	void		*ptr;
	t_img		img;
	t_map		*map;
	t_header	*header;
	t_keys		keys;
	t_textures	*tex;

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
t_mlx			*ft_mlx_init(t_map *map, t_header *header, t_textures *tex);
void			player_init(t_map *map);
void			ft_texture_init(t_mlx *mlx, t_textures *tex);
void			init_draw(t_draw_info *draw);

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
int				key_press(int keycode, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);
int				update_game(t_mlx *mlx);

// 2D Rendering
void			ft_2d_init(t_mlx *mlx);
void			put_pixel(t_img *img, int x, int y, int color);
void			draw_square(t_img *img, int x, int y, int size, int color);
void			draw_map(t_mlx *mlx, int tile_size);
void			draw_player(t_mlx *mlx, int tile_size, int player_size);
int				draw_loop(t_mlx *mlx);
// raycast
void			ft_ray_maker(t_player *player, int x, int screen_width);
void			ft_dda(t_player *player, t_map *map);
void			ft_wall_dist(t_player *player);
int				ft_3d(t_mlx *mlx);
t_texture		*get_texture(t_player *player, t_textures *tex);
void			ft_line_height(t_player *player);

// void		close_window(void);
void			error_map_exit(t_map *init_map);
void			error_exit_header(t_header *init);
void			cleanup_all(t_header *header, t_map *map);
void			free_2d_array(char **array);
void			error_exit_all(char *msg, t_header *header, t_map *map);

// xpm_control.c
void	is_xpm_valid(t_map *map, t_header *header, int type);

// is_map_close.c
void	is_map_closed(t_map *map, t_header *header);

// main_control.c
void	control_map(t_map *map, t_header *header);

// calculate_FPS.c
void ft_calc_FPS(t_player *player);

#endif