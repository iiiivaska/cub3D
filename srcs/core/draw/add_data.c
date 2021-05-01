/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:46:55 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:11:22 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	add_data(t_all *all, int i)
{
	all->s->p[i]->x_sc = (all->map->width / 2) - all->s->p[i]->dir_p
		* all->map->width / (M_PI / 3);
	all->s->p[i]->y_sc = (all->map->height / 2) - (all->s->p[i]->size_2 / 2);
	all->s->p[i]->s = (double)SCALE / all->s->p[i]->size;
}
