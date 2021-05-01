/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:31:22 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 19:46:13 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_cub(t_all *all)
{
	int	i;

	i = (int)ft_strlen(all->map->path);
	i--;
	while (ft_is_space(all->map->path[i]))
		i--;
	i++;
	all->map->path[i] = '\0';
	if (all->map->path[i - 3] != 'c' | all->map->path[i - 2] != 'u'
		| all->map->path[i - 1] != 'b' | all->map->path[i - 4] != '.')
	{
		all->error = "Invalid extension (needs .cub)";
		ft_exit(all, 2);
	}
}
