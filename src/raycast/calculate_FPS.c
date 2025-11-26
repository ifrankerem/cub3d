/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_FPS.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:47:50 by buket             #+#    #+#             */
/*   Updated: 2025/11/26 17:16:19 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static long long get_time_ms()
{
    struct timeval tv;
    long long time;

    gettimeofday(&tv, NULL);
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return time;
}

void ft_calc_FPS(t_player *player)
{
    double oldTime;
    double frameTime;

    oldTime = player->time;
    player->time = get_time_ms();
    frameTime = (player->time - oldTime) / 1000.0;
    player->move_speed = frameTime * 5.0; // bu 5 ve 3 değerleri değişebilir.
    player->rot_speed = frameTime * 3.0; 
}