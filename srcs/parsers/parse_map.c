/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:20:02 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:25:56 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	create_plr(int x, int y, char dir, t_all *all)
{
	all->plr->x = x * SCALE + SCALE / 2;
	all->plr->y = y * SCALE + SCALE / 2;
	if (dir == 'N')
		all->plr->dir = 0;
	if (dir == 'E')
		all->plr->dir = M_PI_2;
	if (dir == 'S')
		all->plr->dir = M_PI;
	if (dir == 'W')
		all->plr->dir = M_PI * (float)3 / 2;
}

void	find_plr(t_all *all)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (all->map->map[y] != 0)
	{
		x = 0;
		while (x < (int)ft_strlen(all->map->map[y]))
		{
			if (all->map->map[y][x] == 'W' || all->map->map[y][x] == 'N'
			|| all->map->map[y][x] == 'S' || all->map->map[y][x] == 'E')
				create_plr(x, y, (all->map->map[y][x]), all);
			x++;
		}
		y++;
	}
}

void	map_parcer(t_all *all, t_list **head)
{
	char	**map;
	int		i;
	t_list	*tmp;

	tmp = *head;
	i = -1;
	map = ft_calloc(ft_lstsize(*head) + 1, sizeof(char *));
	if (!map)
		ft_exit(all, 3);
	while (tmp && !ft_isempty(tmp->content))
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	map[++i] = 0;
	all->map->map = map;
	all->map->row = i;
	find_plr(all);
}
