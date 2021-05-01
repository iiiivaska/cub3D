/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:37:00 by eghis             #+#    #+#             */
/*   Updated: 2021/03/25 19:25:33 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	print_ceiling(t_all *all, int start, int k)
{
	while (start > 0)
	{
		my_mlx_pixel_put(all, k, start, all->map->c->color);
		start--;
	}
}

void	print_floor(t_all *all, int start, int k)
{
	while (start < all->map->height)
	{
		my_mlx_pixel_put(all, k, start, all->map->f->color);
		start++;
	}
}
