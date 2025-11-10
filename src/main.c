/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:46:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/10 17:45:02 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_header	*header;
	t_map		*map;
	t_mlx		*mlx;

	if (argc != 2)
		return (ft_putendl_fd("Error\nInvalid Program Use!", 2), 1);
	header = init_header();
	map = init_map();
	main_parser(argv[1], header, map);
	player_init(map);
	mlx = ft_mlx_init(map, header);
	open_window(mlx, map, header);
	mlx_loop_hook(mlx->ptr, draw_loop, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
