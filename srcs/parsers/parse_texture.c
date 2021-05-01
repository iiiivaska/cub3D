/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:42:07 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 10:15:40 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_flag(t_all *all, char *str, int flag)
{
	if (flag == 1)
		all->map->no = str;
	else if (flag == 2)
		all->map->so = str;
	else if (flag == 3)
		all->map->we = str;
	else if (flag == 4)
		all->map->ea = str;
	else if (flag == 5)
		all->map->s = str;
}

void	parse_texture(t_all *all, char *str, int flag)
{
	char	*str1;
	int		i;
	int		j;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (flag == 1 || flag == 2 || flag == 3 || flag == 4)
		i += 2;
	else
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	j = i;
	while (str[j] && !ft_is_space(str[j]))
		j++;
	str1 = ft_calloc(j - i + 1, sizeof(char));
	if (!str1)
		ft_exit(all, 3);
	j = 0;
	while (str[i] && !ft_is_space(str[i]))
		str1[j++] = str[i++];
	str1[j] = '\0';
	set_flag(all, str1, flag);
}
