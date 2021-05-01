/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:39:55 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:20:21 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	toward(t_all *all)
{
	if (all->map->map[(int)((all->plr->y + sin(all->plr->dir) * SPEED) / SCALE)]
	[(int)((all->plr->x + cos(all->plr->dir) * SPEED) / SCALE)] != '1')
	{
		all->plr->y += sin(all->plr->dir) * SPEED;
		all->plr->x += cos(all->plr->dir) * SPEED;
	}
}

void	backward(t_all *all)
{
	if (all->map->map[(int)((all->plr->y - sin(all->plr->dir) * SPEED) / SCALE)]
	[((int)(all->plr->x - cos(all->plr->dir) * SPEED) / SCALE)] != '1')
	{
		all->plr->y -= sin(all->plr->dir) * SPEED;
		all->plr->x -= cos(all->plr->dir) * SPEED;
	}
}

void	right(t_all *all)
{
	if (all->map->map[(int)((all->plr->y + cos(all->plr->dir) * SPEED) / SCALE)]
	[(int)((all->plr->x - sin(all->plr->dir) * SPEED) / SCALE)] != '1')
	{
		all->plr->y += cos(all->plr->dir) * SPEED;
		all->plr->x -= sin(all->plr->dir) * SPEED;
	}
}

void	left(t_all *all)
{
	if (all->map->map[((int)(all->plr->y - cos(all->plr->dir) * SPEED) / SCALE)]
	[(int)((all->plr->x + sin(all->plr->dir) * SPEED) / SCALE)] != '1')
	{
		all->plr->y -= cos(all->plr->dir) * SPEED;
		all->plr->x += sin(all->plr->dir) * SPEED;
	}
}

int	key_press(int key, t_all *all)
{
	mlx_clear_window(all->win->mlx, all->win->win);
	if (key == TOWARD)
		toward(all);
	if (key == BACKWARD)
		backward(all);
	if (key == RIGHT)
		right(all);
	if (key == LEFT)
		left(all);
	if (key == CAM_LEFT)
	{
		all->plr->dir -= 0.05;
		if (all->plr->dir < 0)
			all->plr->dir = (M_PI * 2) - 0.05;
	}
	if (key == CAM_RIGHT)
	{
		all->plr->dir += 0.05;
		if (all->plr->dir > M_PI * 2)
			all->plr->dir = 0.05;
	}
	if (key == ESC)
		ft_exit(all, 1);
	draw(all);
	return (0);
}
