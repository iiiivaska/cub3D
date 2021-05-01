/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:54:01 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:08:33 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_no_so(t_all *all)
{
	int	fd;

	fd = 0;
	fd = open(all->map->no, O_RDONLY);
	if (fd < 0)
	{
		ft_exit(all, 3);
	}
	close(fd);
	fd = open(all->map->so, O_RDONLY);
	if (fd < 0)
	{
		ft_exit(all, 3);
	}
	close(fd);
}

void	check_we_ea_s(t_all *all)
{
	int	fd;

	fd = 0;
	fd = open(all->map->ea, O_RDONLY);
	if (fd < 0)
	{
		ft_exit(all, 3);
	}
	close(fd);
	fd = open(all->map->we, O_RDONLY);
	if (fd < 0)
	{
		ft_exit(all, 3);
	}
	close(fd);
	fd = open(all->map->s, O_RDONLY);
	if (fd < 0)
	{
		ft_exit(all, 3);
	}
	close(fd);
}

void	check_paths(t_all *all)
{
	check_no_so(all);
	check_we_ea_s(all);
}
