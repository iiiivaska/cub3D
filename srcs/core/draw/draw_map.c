/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:32:13 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:12:37 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	print_ray_mini(t_all *all)
{
	float	start;
	float	end;
	t_point	p;

	start = all->plr->dir - M_PI / 6;
	end = all->plr->dir + M_PI / 6;
	while (start < end)
	{
		p.x = all->plr->x;
		p.y = all->plr->y;
		while (all->map->map[(int)(p.y) / SCALE][(int)(p.x) / SCALE] != '1')
		{
			p.y += sin(start);
			p.x += cos(start);
			my_mlx_pixel_put(all, MINI_MAP * p.x / SCALE + 5,
				MINI_MAP * p.y / SCALE + 5, 0xffa500);
		}
		start += (M_PI / 3) / all->map->width;
	}
}

void	print_sq(t_all *all, t_point *point, int color)
{
	t_point	c_p;

	c_p.y = 0;
	while (c_p.y < MINI_MAP)
	{
		c_p.x = 0;
		while (c_p.x < MINI_MAP)
		{
			my_mlx_pixel_put(all, (point->x) * MINI_MAP + c_p.x + 5,
				(point->y) * MINI_MAP + c_p.y + 5, color);
			c_p.x++;
		}
		c_p.y++;
	}
}

int	check_size(t_all *all)
{
	int	i;

	i = 0;
	while (all->map->map[i])
	{
		if ((int)(ft_strlen(all->map->map[i]) * MINI_MAP) > all->map->width)
			return (1);
		i++;
	}
	if ((i * MINI_MAP) > all->map->height)
		return (1);
	return (0);
}

void	draw_map(t_all *all)
{
	t_point	point;

	if (check_size(all))
		return ;
	print_ray_mini(all);
	point.y = 0;
	while (all->map->map[(int)point.y])
	{
		point.x = 0;
		while (point.x < ft_strlen(all->map->map[(int)point.y]))
		{
			if (all->map->map[(int)point.y][(int)point.x] == '1')
				print_sq(all, &point, 0xFFFFFF);
			if (all->map->map[(int)point.y][(int)point.x] == '2')
				print_sq(all, &point, 0xFF0000);
			point.x++;
		}
		point.y++;
	}
}
