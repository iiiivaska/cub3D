/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:30:03 by eghis             #+#    #+#             */
/*   Updated: 2021/04/25 13:40:39 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_file_errors_3(t_all *all, t_check *check)
{
	if (check->trash == 1)
	{
		all->error = "Trash in file";
		ft_exit(all, 2);
	}
	if (all->map->height <= 30 || all->map->width <= 30)
	{
		all->error = "Wrong resolution";
		ft_exit(all, 2);
	}
}

void	check_file_errors_2(t_all *all, t_check *check)
{
	if (check->ea != 1)
	{
		all->error = "Somethimg wrong in EA";
		ft_exit(all, 2);
	}
	if (check->s != 1)
	{
		all->error = "Somethimg wrong in S";
		ft_exit(all, 2);
	}
	if (check->c != 1)
	{
		all->error = "Somethimg wrong in C";
		ft_exit(all, 2);
	}
	if (check->f != 1)
	{
		all->error = "Somethimg wrong in F";
		ft_exit(all, 2);
	}
	check_file_errors_3(all, check);
}

void	check_file_errors(t_all *all, t_check *check)
{
	if (check->r != 1)
	{
		all->error = "Somethimg wrong in Res";
		ft_exit(all, 2);
	}
	if (check->we != 1)
	{
		all->error = "Somethimg wrong in WE";
		ft_exit(all, 2);
	}
	if (check->so != 1)
	{
		all->error = "Somethimg wrong in SO";
		ft_exit(all, 2);
	}
	if (check->no != 1)
	{
		all->error = "Somethimg wrong in NO";
		ft_exit(all, 2);
	}
	check_file_errors_2(all, check);
}
