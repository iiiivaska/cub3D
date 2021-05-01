/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:24:29 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 12:17:18 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	close_window(t_all *all)
{
	clean(all);
	exit(0);
}

void	ft_error(t_all *all)
{
	clean(all);
	write(1, "Error\n", 6);
	write(1, all->error, ft_strlen(all->error));
	exit(0);
}

void	p_error(t_all *all)
{
	clean(all);
	perror("Error\nError");
	exit(0);
}

void	ft_exit(t_all *all, int flag)
{
	if (flag == 1)
		close_window(all);
	if (flag == 2)
		ft_error(all);
	if (flag == 3)
		p_error(all);
}

int	ft_exit_2(t_all *all)
{
	close_window(all);
	return (0);
}
