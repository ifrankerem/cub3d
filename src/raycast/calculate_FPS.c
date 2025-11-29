/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_FPS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:47:50 by buket             #+#    #+#             */
/*   Updated: 2025/11/29 15:17:34 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long long	get_time_ms(void)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	ft_calc_FPS(t_player *player)
{
	double oldTime;
	double frameTime;

	oldTime = player->time;
	player->time = get_time_ms();
	frameTime = (player->time - oldTime) / 1000.0;
	player->move_speed = frameTime * MOVE_SPEED;
	player->rot_speed = frameTime * ROT_SPEED;
}
