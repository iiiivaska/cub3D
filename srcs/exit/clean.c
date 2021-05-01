/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:53:19 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 12:21:27 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	lst_clear(t_list *list)
{
	t_list	*head;
	t_list	*temp;

	head = list;
	if (head)
	{
		while (head)
		{
			temp = head;
			head = head->next;
			if (temp->content)
				free(temp->content);
			if (temp)
				free(temp);
		}
	}
}

void	sp_clean(t_all *all)
{
	int	i;

	i = 0;
	if (all->s->p)
	{
		while (all->s->p[i])
		{
			if (all->s->p[i])
				free(all->s->p[i]);
			i++;
		}
		free(all->s->p);
	}
}

void	clean(t_all *all)
{
	if (all->map->f)
		free(all->map->f);
	if (all->map->c)
		free(all->map->c);
	lst_clear(all->file);
	if (all->map->map)
		free(all->map->map);
	if (all->ray->direct)
		free(all->ray->direct);
	if (all->ray->lenght)
		free(all->ray->lenght);
	sp_clean(all);
	if (all->win->img)
		mlx_destroy_image(all->win->mlx, all->win->img);
	if (all->win->win)
		mlx_destroy_window(all->win->mlx, all->win->win);
}
