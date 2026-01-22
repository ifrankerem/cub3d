/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_FPS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:47:50 by buket             #+#    #+#             */
/*   Updated: 2025/12/27 15:36:44 by bucolak          ###   ########.fr       */
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

void	ft_calc_fps(t_player *player)
{
	double	old_time;
	double	frame_time;

	old_time = player->time;
	player->time = get_time_ms();
	frame_time = (player->time - old_time) / 1000.0;
	player->move_speed = frame_time * MOVE_SPEED;
	player->rot_speed = frame_time * ROT_SPEED;
}
