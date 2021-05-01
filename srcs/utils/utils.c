/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:54:36 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:31:23 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_isempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_space(char ch)
{
	if (!ch)
		return (0);
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == 'v' || ch == '\f'
		|| ch == '\r')
		return (1);
	return (0);
}
