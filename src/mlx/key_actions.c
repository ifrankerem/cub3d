/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:27:25 by buket             #+#    #+#             */
/*   Updated: 2025/11/29 15:27:47 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
		close_window(mlx);
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		mlx->keys.w = 1;
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		mlx->keys.s = 1;
	if (keycode == XK_a || keycode == XK_A)
		mlx->keys.a = 1;
	if (keycode == XK_d || keycode == XK_D)
		mlx->keys.d = 1;
	if (keycode == XK_Right)
		mlx->keys.right = 1;
	if (keycode == XK_Left)
		mlx->keys.left = 1;
	return (0);
}

int	key_release(int keycode, t_mlx *mlx)
{
	if (keycode == XK_w || keycode == XK_W || keycode == XK_Up)
		mlx->keys.w = 0;
	if (keycode == XK_s || keycode == XK_S || keycode == XK_Down)
		mlx->keys.s = 0;
	if (keycode == XK_a || keycode == XK_A)
		mlx->keys.a = 0;
	if (keycode == XK_d || keycode == XK_D)
		mlx->keys.d = 0;
	if (keycode == XK_Right)
		mlx->keys.right = 0;
	if (keycode == XK_Left)
		mlx->keys.left = 0;
	return (0);
}
