/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:22:31 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 12:35:25 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	parse(t_all *all)
{
	file_to_list(all);
	parse_flags(all);
	convert_color(all);
	if (all->map->map == 0)
	{
		all->error = "No Map";
		ft_exit(all, 2);
	}
	parse_sprites(all);
	max_res(all);
}
