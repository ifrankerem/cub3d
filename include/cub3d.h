/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:44:36 by iarslan           #+#    #+#             */
/*   Updated: 2025/12/27 17:02:04 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define WIN_W 1920
# define WIN_H 1080
# define FOV_DEG 66.0
# define M_PI 3.14159265358979323846
# define ROT_SPEED 2.0
# define MOVE_SPEED 3.0

enum			e_TYPE
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

enum			e_ORIENTATION
{
	N,
	S,
	W,
	E,
};

enum			e_KEY
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

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}				t_texture;

typedef struct s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	int			floor_color;
	int			ceiling_color;
}				t_textures;

typedef struct s_draw_info
{
	t_texture	*tex;
	double		step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
}				t_draw_info;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_player
{
	double		x;
	double		y;
	long long	time;
	double		move_speed;
	double		rot_speed;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		raydir_x;
	double		raydir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			wall_hit;
	int			side;

	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;

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
	int			right;
	int			left;
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

void			main_parser(char *header, t_header *init, t_map *map);
void			header_parse(int fd, t_header *init, t_map *init_map);
void			map_parse(t_map *map, t_header *header);

t_header		*init_header(void);
t_map			*init_map(void);
t_mlx			*ft_mlx_init(t_map *map, t_header *header, t_textures *tex);
void			ft_texture_init(t_mlx *mlx, t_textures *tex);
void			init_draw(t_draw_info *draw);

void			player_init(t_map *map);
void			img_control(void *img, t_mlx *mlx);

int				ft_isspace(char c);
char			*ft_path_maker(char *line, t_header *init, t_map *map, int fd);
int				ft_atol(const char *nptr);
void			*ft_grid_maker(size_t count, size_t size, t_map *init_map,
					t_header *header);
void			raw_map_filler(char *line, t_map *init_map, int fd,
					t_header *header);
int				is_map_started(char *line);

void			fill_space(char **cpy_map, int x, int y, t_map *map);
void			flood_fill_for_space(char **cpy_map, t_map *map);
char			**make_copy(t_map *map, t_header *header);
void			copy_mapcontrol_space(t_map *map, char **cpy_map,
					t_header *header);

void			ff_playable(char **cpy_map, int x, int y, t_map *map);
int				is_map_multipel(char **cpy_map);

void			open_window(t_mlx *mlx, t_map *map, t_header *header);
int				close_window(t_mlx *mlx);
int				key_press(int keycode, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);
int				update_game(t_mlx *mlx);

void			ft_ray_maker(t_player *player, int x, int screen_width);
void			ft_dda(t_player *player, t_map *map);
void			ft_wall_dist(t_player *player);
int				ft_3d(t_mlx *mlx);
t_texture		*get_texture(t_player *player, t_textures *tex);
void			ft_line_height(t_player *player);

void			error_map_exit(t_map *init_map);
void			error_exit_header(t_header *init);
void			cleanup_all(t_header *header, t_map *map, t_mlx *mlx);
void			free_2d_array(char **array);
void			error_exit_all(char *msg, t_header *header, t_map *map,
					t_mlx *mlx);
void			cleanup_gnl(int fd);

int				is_xpm_valid(t_header *header, int type);

void			is_map_closed(t_map *map, t_header *header);

void			ft_calc_fps(t_player *player);
long long		get_time_ms(void);

int				load_no(t_header *header, t_map *map, char *line, int fd);
int				load_so(t_header *header, t_map *map, char *line, int fd);
int				load_we(t_header *header, t_map *map, char *line, int fd);
int				load_ea(t_header *header, t_map *map, char *line, int fd);

int				identifier_load(t_header *header, t_map *map, char *line,
					int fd);

int				f_c_load(t_header *header, char *ptr);

void			is_chars_valid(t_map *map, t_header *header);
void			is_empty_line(t_map *map, t_header *header);

void			start_draw(t_player *ray, int x, t_mlx *mlx, t_draw_info *draw);

int				key_press(int keycode, t_mlx *mlx);
int				key_release(int keycode, t_mlx *mlx);

#endif