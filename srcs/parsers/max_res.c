/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_res.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:45:41 by eghis             #+#    #+#             */
/*   Updated: 2021/04/29 22:32:29 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	max_res_2(t_all *all)
{
	if (all->map->height <= 500)
		all->trian = 1;
	else
		all->trian = all->map->height / (SCALE * 8);
	if (all->map->width <= 500)
		all->trian_2 = 1;
	else
		all->trian_2 = all->map->width / (SCALE * 8);
}

void	max_res(t_all *all)
{
	int	dis_width;
	int	dis_height;

	mlx_get_screen_size(all->win->mlx, &dis_width, &dis_height);
	if (all->map->height <= 35 || all->map->width <= 35)
	{
		all->error = "Wrong Res";
		ft_exit(all, 2);
	}
	if (all->map->height > dis_height)
		all->map->height = dis_height;
	if (all->map->width > dis_width)
		all->map->width = dis_width;
	all->ray->lenght = (int *)malloc(sizeof(int) * all->map->width);
	if (!(all->ray->lenght))
		ft_exit(all, 3);
	all->ray->direct = (double *)malloc(sizeof(double) * all->map->width);
	if (!(all->ray->direct))
		ft_exit(all, 3);
	max_res_2(all);
}
