/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:07:50 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 11:00:52 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_last(t_all *all)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	all->error = "Wrong map!";
	while (all->map->map[y] != 0)
		y++;
	while (all->map->map[y - 1][x] != 0)
	{
		if (all->map->map[y - 1][x] != ' ' && all->map->map[y - 1][x] != '1')
			ft_exit(all, 2);
		x++;
	}
}

void	check_players(t_all *all)
{
	int	x;
	int	y;
	int	k;

	k = 0;
	y = 0;
	while (all->map->map[y])
	{
		x = 0;
		while (all->map->map[y][x])
		{
			if (all->map->map[y][x] == 'W' || all->map->map[y][x] == 'S' ||
			all->map->map[y][x] == 'E' || all->map->map[y][x] == 'N')
				k++;
			x++;
		}
		y++;
	}
	if (k != 1)
	{
		all->error = "Invalid count of players\n";
		ft_exit(all, 2);
	}
}

void	check_symbols(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (all->map->map[y])
	{
		x = 0;
		while (all->map->map[y][x])
		{
			if (!ft_is_space(all->map->map[y][x]) && all->map->map[y][x] != '2'
			&& all->map->map[y][x] != '1' && all->map->map[y][x] != 'W' &&
			all->map->map[y][x] != 'S' && all->map->map[y][x] != 'E' &&
			all->map->map[y][x] != 'N' && all->map->map[y][x] != '0')
			{
				printf("%c", all->map->map[y][x]);
				all->error = "Invalid symbol in map\n";
				ft_exit(all, 2);
			}
			x++;
		}
		y++;
	}
}

void	check_map(t_all *all)
{
	check_last(all);
	check_symbols(all);
	check_players(all);
	check_close(all, (all->plr->x - SCALE / 2) / SCALE,
		(all->plr->y - SCALE / 2) / SCALE);
}
