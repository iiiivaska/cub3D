/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:38:35 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 08:07:54 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	get_width(t_all *all)
{
	if (all->ray->text == 'N')
		return (all->no->width);
	if (all->ray->text == 'S')
		return (all->so->width);
	if (all->ray->text == 'W')
		return (all->we->width);
	if (all->ray->text == 'E')
		return (all->ea->width);
	return (0);
}

int	get_height(t_all *all)
{
	if (all->ray->text == 'N')
		return (all->no->height);
	if (all->ray->text == 'S')
		return (all->so->height);
	if (all->ray->text == 'W')
		return (all->we->height);
	if (all->ray->text == 'E')
		return (all->ea->height);
	return (0);
}

int	find_pix(t_all *all, int size, int n_y)
{
	char	*clr;
	float	x;
	float	y;
	int		x_i;
	int		y_i;

	x = all->ray->x / SCALE - (int)all->ray->x / SCALE;
	y = all->ray->y / SCALE - (int)all->ray->y / SCALE;
	y_i = n_y * get_height(all) / size;
	if (all->ray->text == 'N' || all->ray->text == 'S')
		x_i = x * get_width(all);
	else
		x_i = y * get_width(all);
	if (all->ray->text == 'N')
		clr = all->no->addr + (y_i * all->no->l_l + x_i * (all->no->bpp / 8));
	if (all->ray->text == 'W')
		clr = all->we->addr + (y_i * all->we->l_l + x_i * (all->we->bpp / 8));
	if (all->ray->text == 'E')
		clr = all->ea->addr + (y_i * all->ea->l_l + x_i * (all->ea->bpp / 8));
	if (all->ray->text == 'S')
		clr = all->so->addr + (y_i * all->so->l_l + x_i * (all->so->bpp / 8));
	return (*(unsigned int *)clr);
}

int	find_pix_2(t_all *all, int n_x, int n_y)
{
	char	*clr;

	n_x = n_x * all->s->h_s;
	n_y = n_y * all->s->w_s;
	clr = all->s->addr + (n_y * all->s->l_l + n_x * (all->s->bpp / 8));
	return (*(unsigned int *)clr);
}
