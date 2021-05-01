/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shaders.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:25:58 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:22:35 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_shaders(t_all *all)
{
	all->ea->img = mlx_xpm_file_to_image(all->win->mlx, all->map->ea,
			&all->ea->width, &all->ea->height);
	all->ea->addr = mlx_get_data_addr(all->ea->img, &all->ea->bpp,
			&all->ea->l_l, &all->ea->end);
	all->we->img = mlx_xpm_file_to_image(all->win->mlx, all->map->we,
			&all->we->width, &all->we->height);
	all->we->addr = mlx_get_data_addr(all->we->img, &all->we->bpp,
			&all->we->l_l, &all->we->end);
	all->so->img = mlx_xpm_file_to_image(all->win->mlx, all->map->so,
			&all->so->width, &all->so->height);
	all->so->addr = mlx_get_data_addr(all->so->img, &all->so->bpp,
			&all->so->l_l, &all->so->end);
	all->no->img = mlx_xpm_file_to_image(all->win->mlx, all->map->no,
			&all->no->width, &all->no->height);
	all->no->addr = mlx_get_data_addr(all->no->img, &all->no->bpp,
			&all->no->l_l, &all->no->end);
	all->s->img = mlx_xpm_file_to_image(all->win->mlx, all->map->s,
			&all->s->width, &all->s->height);
	all->s->addr = mlx_get_data_addr(all->s->img, &all->s->bpp,
			&all->s->l_l, &all->s->end);
}
