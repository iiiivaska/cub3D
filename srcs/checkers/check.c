/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:52:01 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:00:26 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_2(t_all *all)
{
	if (all->map->ea[ft_strlen(all->map->ea) - 1] != 'm'
		|| all->map->ea[ft_strlen(all->map->ea) - 2] != 'p'
		|| all->map->ea[ft_strlen(all->map->ea) - 3] != 'x'
		|| all->map->ea[ft_strlen(all->map->ea) - 4] != '.')
		ft_exit(all, 2);
	if (all->map->we[ft_strlen(all->map->we) - 1] != 'm'
		|| all->map->we[ft_strlen(all->map->we) - 2] != 'p'
		|| all->map->we[ft_strlen(all->map->we) - 3] != 'x'
		|| all->map->we[ft_strlen(all->map->we) - 4] != '.')
		ft_exit(all, 2);
	if (all->map->s[ft_strlen(all->map->s) - 1] != 'm'
		|| all->map->s[ft_strlen(all->map->s) - 2] != 'p'
		|| all->map->s[ft_strlen(all->map->s) - 3] != 'x'
		|| all->map->s[ft_strlen(all->map->s) - 4] != '.')
		ft_exit(all, 2);
}

void	check(t_all *all)
{
	check_file(all);
	check_map(all);
	check_colors(all);
	check_paths(all);
	all->error = "Textures not .xpm";
	if (all->map->no[ft_strlen(all->map->no) - 1] != 'm'
		|| all->map->no[ft_strlen(all->map->no) - 2] != 'p'
		|| all->map->no[ft_strlen(all->map->no) - 3] != 'x'
		|| all->map->no[ft_strlen(all->map->no) - 4] != '.')
		ft_exit(all, 2);
	if (all->map->so[ft_strlen(all->map->so) - 1] != 'm'
		|| all->map->so[ft_strlen(all->map->so) - 2] != 'p'
		|| all->map->so[ft_strlen(all->map->so) - 3] != 'x'
		|| all->map->so[ft_strlen(all->map->so) - 4] != '.')
		ft_exit(all, 2);
	check_2(all);
}
