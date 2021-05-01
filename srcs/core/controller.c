/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:20:52 by eghis             #+#    #+#             */
/*   Updated: 2021/04/29 17:46:34 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	controller(t_all *all)
{
	parse(all);
	check(all);
	all->win->mlx = mlx_init();
	if (all->save != 1)
		all->win->win = mlx_new_window(all->win->mlx, all->map->width,
				all->map->height, "cub3D");
	get_shaders(all);
	all->win->img = mlx_new_image(all->win->mlx, all->map->width,
			all->map->height);
	all->win->addr = mlx_get_data_addr(all->win->img, &all->win->bpp,
			&all->win->linel, &all->win->en);
	draw(all);
	mlx_hook(all->win->win, 2, (1L << 0), &key_press, all);
	mlx_hook(all->win->win, 17, (1L << 17), &ft_exit_2, all);
	mlx_loop(all->win->mlx);
}
