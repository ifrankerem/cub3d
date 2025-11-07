/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 23:46:43 by iarslan           #+#    #+#             */
/*   Updated: 2025/11/07 02:30:13 by iarslan          ###   ########.fr       */
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
	mlx = ft_mlx_init(map, header);
	main_parser(argv[1], header, map);
	open_window(mlx, map, header);
	mlx_key_hook(mlx->win, movement_and_exit, mlx);
	mlx_hook(mlx->win, 17, 0, close_window, mlx);
	mlx_loop(mlx->ptr);
	// debug(map, header);
	return (0);
}
