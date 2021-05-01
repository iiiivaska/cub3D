/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:24:10 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 10:45:11 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_map_2(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_close_2(t_all *all, char **map, int x, int y)
{
	if (!map[y][x] || x < 0 || y < 0 || ft_is_space(map[y][x]))
	{
		free_map_2(map);
		ft_exit(all, 2);
	}
	if (map[y][x] == '1' || map[y][x] == 1 || map[y][x] == 2)
		return ;
	if (map[y][x] == '2')
		map[y][x] = 2;
	else
		map[y][x] = 1;
	check_close_2(all, map, x + 1, y);
	check_close_2(all, map, x - 1, y);
	check_close_2(all, map, x, y + 1);
	check_close_2(all, map, x, y - 1);
	check_close_2(all, map, x - 1, y - 1);
	check_close_2(all, map, x + 1, y + 1);
	check_close_2(all, map, x - 1, y + 1);
	check_close_2(all, map, x + 1, y - 1);
}

char	**copy_map_2(t_all *all, char **map)
{
	int	i;
	int	k;

	i = 0;
	while (all->map->map[i])
	{
		k = 0;
		while (all->map->map[i][k])
		{
			map[i][k] = all->map->map[i][k];
			k++;
		}
		map[i][k] = '\0';
		i++;
	}
	map[i] = 0;
	return (map);
}

char	**copy_map(t_all *all, char **map)
{
	int	i;
	int	k;

	i = 0;
	while (all->map->map[i])
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!map)
		ft_exit(all, 3);
	i = 0;
	while (all->map->map[i])
	{
		k = 0;
		while (all->map->map[i][k])
			k++;
		map[i] = (char *)malloc(sizeof(char) * (k + 1));
		if (!map[i])
			ft_exit(all, 3);
		i++;
	}
	return (copy_map_2(all, map));
}

void	check_close(t_all *all, int x, int y)
{
	char	**map;

	all->error = "Map not inclose";
	map = 0;
	map = copy_map(all, map);
	check_close_2(all, map, x, y);
	free_map_2(map);
	all->error = 0;
}
