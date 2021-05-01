/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:11:57 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 08:17:13 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_r(char *str, t_check *check)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '\0')
		return ;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (!ft_is_space(str[i]) && str[i] != '\0')
		return ;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return ;
	check->r++;
}
