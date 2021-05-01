/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:41:03 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:20:47 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_ex_res(t_all *all)
{
	if (all->map->f == 0 || all->map->c == 0)
	{
		all->error = "F or C is empty";
		ft_exit(all, 2);
	}
}

void	convert_color(t_all *all)
{
	int	clr;

	check_ex_res(all);
	clr = 0;
	clr = all->map->f->r;
	clr = (clr << 8) + all->map->f->g;
	clr = (clr << 8) + all->map->f->b;
	all->map->f->color = clr;
	clr = 0;
	clr = all->map->c->r;
	clr = (clr << 8) + all->map->c->g;
	clr = (clr << 8) + all->map->c->b;
	all->map->c->color = clr;
}
