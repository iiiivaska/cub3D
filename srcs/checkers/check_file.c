/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:40:52 by eghis             #+#    #+#             */
/*   Updated: 2021/04/29 14:35:55 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_map_2(char *str)
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

int	get_flag_2(char *str)
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

int	finder_2(char *str, t_check *check)
{
	int		flag;

	flag = get_flag_2(str);
	if (flag == 1)
		check_r(str, check);
	else if (flag == 2)
		check_texture(str, 1, check);
	else if (flag == 3)
		check_texture(str, 2, check);
	else if (flag == 4)
		check_texture(str, 3, check);
	else if (flag == 5)
		check_texture(str, 4, check);
	else if (flag == 6)
		check_texture(str, 5, check);
	else if (flag == 7)
		check_f_c(str, check, 1);
	else if (flag == 8)
		check_f_c(str, check, 2);
	else if (!is_map_2(str))
		check_empty(str, check);
	return (is_map_2(str));
}

void	check_after_map(t_all *all, t_list *head)
{
	int		i;
	char	*str;

	while (head != 0)
	{
		i = 0;
		if (head->content)
		{
			str = head->content;
			while (str[i])
			{
				if (!ft_is_space(str[i]) && str[i] != '\n')
				{
					all->error = "Trash after map";
					ft_exit(all, 2);
				}
				i++;
			}
		}
		head = head->next;
	}
}

void	check_file(t_all *all)
{
	t_list	*head;
	t_check	check;

	check.we = 0;
	check.trash = 0;
	check.no = 0;
	check.so = 0;
	check.ea = 0;
	check.s = 0;
	check.f = 0;
	check.c = 0;
	check.r = 0;
	head = all->file;
	while (head != 0)
	{
		if (finder_2(head->content, &check) == 1)
		{
			head = skip_map(head);
			check_after_map(all, head);
		}
		else
			head = head->next;
	}
	check_file_errors(all, &check);
}
