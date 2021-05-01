/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:54:22 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:25:32 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_map(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (!ft_is_space(str[i]) && str[i] != '1')
			return (0);
		if (str[i] == '1')
			k++;
		i++;
	}
	if (k == 0)
		return (0);
	return (1);
}

int	get_flag(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == 'R')
		return (1);
	if (str[i] == 'N' && str[i + 1] == 'O')
		return (2);
	if (str[i] == 'S' && str[i + 1] == 'O')
		return (3);
	if (str[i] == 'W' && str[i + 1] == 'E')
		return (4);
	if (str[i] == 'E' && str[i + 1] == 'A')
		return (5);
	if (str[i] == 'S')
		return (6);
	if (str[i] == 'F')
		return (7);
	if (str[i] == 'C')
		return (8);
	return (0);
}

int	finder(t_all *all, char *str)
{
	int	flag;

	flag = get_flag(str);
	if (flag == 1)
		parse_res(all, str);
	else if (flag == 2)
		parse_texture(all, str, 1);
	else if (flag == 3)
		parse_texture(all, str, 2);
	else if (flag == 4)
		parse_texture(all, str, 3);
	else if (flag == 5)
		parse_texture(all, str, 4);
	else if (flag == 6)
		parse_texture(all, str, 5);
	else if (flag == 7)
		parse_f_c(all, str, 1);
	else if (flag == 8)
		parse_f_c(all, str, 2);
	return (is_map(str));
}

void	parse_flags(t_all *all)
{
	t_list	*head;

	head = all->file;
	while (head != 0)
	{
		if (finder(all, head->content) == 1)
		{
			map_parcer(all, &head);
			break ;
		}
		head = head->next;
	}
}
