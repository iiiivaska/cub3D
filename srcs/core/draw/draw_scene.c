/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:30:10 by eghis             #+#    #+#             */
/*   Updated: 2021/04/29 20:45:45 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	find_side(t_all *all)
{
	if ((int)(all->ray->x - cosf(all->ray->dir)) / SCALE ==
		(int)all->ray->x / SCALE)
	{
		if ((int)(all->ray->y - sinf(all->ray->dir)) / SCALE <
		(int)all->ray->y / SCALE)
			all->ray->text = 'N';
		else
			all->ray->text = 'S';
	}
	else if ((int)(all->ray->y - sinf(all->ray->dir)) / SCALE
			== (int)all->ray->y / SCALE)
	{
		if ((int)(all->ray->x - cosf(all->ray->dir)) / SCALE
			< (int)all->ray->x / SCALE)
			all->ray->text = 'W';
		else
			all->ray->text = 'E';
	}
}

void	print_wall_2(t_all *all, int size, int k)
{
	int		z;
	int		g;

	g = size / 2;
	z = all->map->height / 2;
	while (g < size && z < all->map->height)
	{
		my_mlx_pixel_put(all, k, z, find_pix(all, size, g));
		z++;
		g++;
	}
	print_floor(all, z, k);
	z = all->map->height / 2;
	g = size / 2;
	while (g > 0 && z > 0)
	{
		my_mlx_pixel_put(all, k, z, find_pix(all, size, g));
		z--;
		g--;
	}
	print_ceiling(all, z, k);
}

void	print_wall(t_all *all, int k)
{
	double	size;

	find_side(all);
	if (all->ray->len == 0)
		size = all->map->height;
	else
		size = ((double)all->map->height) / (all->ray->len
				* cosf(all->ray->dir - all->plr->dir) / SCALE);
	print_wall_2(all, size, k);
}

void	draw_scene(t_all *all)
{
	double	end;
	int		x;

	x = 0;
	all->ray->dir = (double)all->plr->dir - M_PI / 6;
	end = (double)all->plr->dir + M_PI / 6;
	while (all->ray->dir < end && x < all->map->width)
	{
		all->ray->len = 0;
		all->ray->x = all->plr->x;
		all->ray->y = all->plr->y;
		while (all->map->map[(int)((all->ray->y) / SCALE)]
		[(int)((all->ray->x) / SCALE)] != '1')
		{
			all->ray->y += sinf(all->ray->dir);
			all->ray->x += cosf(all->ray->dir);
			all->ray->len++;
		}
		all->ray->lenght[x] = all->ray->len;
		all->ray->direct[x] = all->ray->dir;
		print_wall(all, x);
		x++;
		all->ray->dir += M_PI / 3 / all->map->width;
	}
}
