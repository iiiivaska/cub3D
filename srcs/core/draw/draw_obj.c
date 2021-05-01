/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:33:59 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 08:07:50 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	prep_s(t_all *all, int i)
{
	t_sp	*sp;
	int		k;

	all->s->w_s = (double)all->s->width / SCALE;
	all->s->h_s = (double)all->s->height / SCALE;
	while (--i)
	{
		k = 0;
		while (i > k)
		{
			if (all->s->p[k]->len > all->s->p[k + 1]->len)
			{
				sp = all->s->p[k];
				all->s->p[k] = all->s->p[k + 1];
				all->s->p[k + 1] = sp;
			}
			k++;
		}
	}
}

void	prnt_obj_3(t_all *all, int i, int y)
{
	int	z;
	int	t;

	z = 0;
	while (z < all->trian_2)
	{
		t = 0;
		while (t < all->trian)
		{
			if (all->s->p[i]->y_sc + y * all->trian + t < all->map->height
				&& all->ray->lenght[all->s->p[i]->x_sc
					+ all->m * all->trian_2 + z] >= all->s->p[i]->len)
				my_mlx_pixel_put(all, all->s->p[i]->x_sc + all->m
					* all->trian_2 + z,
					all->s->p[i]->y_sc + y * all->trian + t, all->color);
			t++;
		}
		z++;
	}
}

void	prnt_obj_2(t_all *all, int i, int x, int y)
{
	if (all->s->p[i]->y_sc + y * all->trian >= 0 && all->s->p[i]->y_sc
		+ y * all->trian < all->map->height)
	{
		all->color = find_pix_2(all, x * all->trian_2 * all->s->p[i]->s,
				y * all->trian * SCALE / (all->s->p[i]->size_2));
		if ((all->color != 0x000000) && all->s->p[i]->len > SCALE / 2)
		{
			prnt_obj_3(all, i, y);
		}
	}
}

void	prnt_obj(t_all *all, int i)
{
	int	y;
	int	x;

	while (i--)
	{
		all->color = 0;
		x = all->s->p[i]->size / all->trian_2;
		all->m = x / 2;
		while (x >= 0)
		{
			if ((all->s->p[i]->x_sc + all->m * all->trian_2 + all->trian_2 > 0
					&& all->s->p[i]->x_sc + all->m * all->trian_2
					<= all->map->width))
			{
				y = 0;
				while (y < all->s->p[i]->size_2 / all->trian)
				{
					prnt_obj_2(all, i, x, y);
					y++;
				}
			}
			all->m--;
			x--;
		}
	}
}

void	draw_obj(t_all *all)
{
	int	i;

	if (all->s->count == 0)
		return ;
	i = 0;
	while (i < all->s->count)
	{
		all->s->p[i]->dir = atan2(all->s->p[i]->y - all->plr->y,
				all->s->p[i]->x - all->plr->x);
		all->s->p[i]->dir_p = all->plr->dir - all->s->p[i]->dir;
		while (all->s->p[i]->dir_p > M_PI)
			all->s->p[i]->dir_p -= 2 * M_PI;
		while (all->s->p[i]->dir_p < -M_PI)
			all->s->p[i]->dir_p += 2 * M_PI;
		all->s->p[i]->len = hypot(all->plr->x - all->s->p[i]->x,
				all->plr->y - all->s->p[i]->y);
		all->s->p[i]->size = (double)all->map->width / (all->s->p[i]->len
				* cosf(all->ray->direct[i] - all->plr->dir)) * (double)SCALE;
		all->s->p[i]->size_2 = (double)all->map->height / (all->s->p[i]->len
				* cosf(all->ray->direct[i] - all->plr->dir)) * (double)SCALE;
		add_data(all, i);
		i++;
	}
	prep_s(all, i);
	prnt_obj(all, i);
}
