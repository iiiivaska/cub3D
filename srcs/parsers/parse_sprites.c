/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:42:16 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:47:33 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_coord_2(t_all *all, int x, int y, int i)
{
	if (all->map->map[y][x] == '2')
	{
		all->s->p[i] = (t_sp *)malloc(sizeof(t_sp));
		if (!(all->s->p[i]))
			ft_exit(all, 3);
		all->s->p[i]->x = x * SCALE + SCALE / 2;
		all->s->p[i]->y = y * SCALE + SCALE / 2;
		return (i + 1);
	}
	return (i);
}

void	get_coord(t_all *all)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	all->s->p = (t_sp **)malloc(sizeof(t_sp) * (all->s->count + 1));
	if (!(all->s->p))
		ft_exit(all, 3);
	while (all->map->map[y])
	{
		x = 0;
		while (all->map->map[y][x])
		{
			i = get_coord_2(all, x, y, i);
			x++;
		}
		y++;
	}
	all->s->p[i] = 0;
}

int	count_sprites(t_all *all)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (all->map->map[y])
	{
		x = 0;
		while (all->map->map[y][x])
		{
			if (all->map->map[y][x] == '2')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

void	parse_sprites(t_all *all)
{
	all->s->count = count_sprites(all);
	if (all->s->count == 0)
		return ;
	get_coord(all);
}
