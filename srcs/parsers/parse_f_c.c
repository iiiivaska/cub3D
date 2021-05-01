/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_f_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:51:52 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:24:36 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_number_2(t_all *all, int x, char *str, char sep)
{
	char	*str1;
	int		l;
	int		num;

	l = x;
	while (str[l] != sep && str[l] && !ft_is_space(str[l]))
	{
		if (!ft_isdigit(str[l]))
		{
			all->error = "R or G or B is not number";
			ft_exit(all, 2);
		}
		l++;
	}
	str1 = ft_calloc(l - x + 1, sizeof(char));
	if (!str1)
		ft_exit(all, 3);
	l = 0;
	while (str[x] != sep && str[x] && str[x] != ' ')
		str1[l++] = str[x++];
	str1[l] = '\0';
	num = ft_atoi(str1);
	free(str1);
	return (num);
}

void	parse_f_c(t_all *all, char *str, int flag)
{
	int		x;
	t_color	*color;

	x = 0;
	color = ft_calloc(1, sizeof(t_color));
	if (!(color))
		ft_exit(all, 3);
	while (!ft_isdigit(str[x]))
		x++;
	color->r = get_number_2(all, x, str, ',');
	while (ft_isdigit(str[x]))
		x++;
	while (!ft_isdigit(str[x]))
		x++;
	color->g = get_number_2(all, x, str, ',');
	while (ft_isdigit(str[x]))
		x++;
	while (!ft_isdigit(str[x]))
		x++;
	color->b = get_number_2(all, x, str, ',');
	if (flag == 1)
		all->map->f = color;
	else if (flag == 2)
		all->map->c = color;
}
