/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:35:45 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 08:20:59 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_flag_2(int flag, t_check *check)
{
	if (flag == 1)
		check->no++;
	if (flag == 2)
		check->so++;
	if (flag == 3)
		check->we++;
	if (flag == 4)
		check->ea++;
	if (flag == 5)
		check->s++;
}

void	check_texture(char *str, int flag, t_check *check)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (flag == 1 || flag == 2 || flag == 3 || flag == 4)
		i += 2;
	else
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i])
		return ;
	while (str[i] && !ft_is_space(str[i]))
		i++;
	if (!ft_is_space(str[i]) && str[i] != '\0')
		return ;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return ;
	set_flag_2(flag, check);
}
