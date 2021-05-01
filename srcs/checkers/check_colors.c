/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:48:29 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:00:25 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_colors(t_all *all)
{
	if (all->map->f->g < 0 || all->map->f->g > 255 || all->map->f->r < 0
		|| all->map->f->r > 255 || all->map->f->b < 0 || all->map->f->b > 255)
	{
		all->error = "Invalid color for Floor";
		ft_exit(all, 2);
	}
	if (all->map->c->g < 0 || all->map->c->g > 255 || all->map->c->r < 0
		|| all->map->c->r > 255 || all->map->c->b < 0 || all->map->c->b > 255)
	{
		all->error = "Invalid color for Ceiling";
		ft_exit(all, 2);
	}
}
