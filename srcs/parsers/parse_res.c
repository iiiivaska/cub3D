/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:03:06 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 12:58:04 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_number(t_all *all, int x, char *str, char sep)
{
	char	*str1;
	int		l;
	int		num;

	l = x;
	while (str[l] != sep && str[l] && !ft_is_space(str[l]))
	{
		if (!ft_isdigit(str[l]))
		{
			all->error = "Resolution is not number";
			ft_exit(all, 2);
		}
		l++;
	}
	str1 = ft_calloc(l - x + 1, sizeof(char));
	if (!str1)
		ft_exit(all, 3);
	l = 0;
	while (str[x] != sep && str[x] && !ft_is_space(str[x]))
		str1[l++] = str[x++];
	str1[l] = '\0';
	num = ft_atoi(str1);
	free(str1);
	return (num);
}

void	parse_res(t_all *all, char *str)
{
	int	x;

	x = 0;
	while (ft_is_space(str[x]))
		x++;
	x++;
	while (str[x] && ft_is_space(str[x]))
		x++;
	all->map->width = get_number(all, x, str, ' ');
	while (str[x] && !ft_is_space(str[x]))
		x++;
	while (str[x] && ft_is_space(str[x]))
		x++;
	all->map->height = get_number(all, x, str, ' ');
}
