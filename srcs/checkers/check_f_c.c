/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_f_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:21:21 by eghis             #+#    #+#             */
/*   Updated: 2021/04/25 13:35:43 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_f_c_3(char *str, t_check *check, int flag, int i)
{
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return ;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return ;
	if (flag == 1)
		check->f++;
	if (flag == 2)
		check->c++;
}

void	check_f_c_2(char *str, t_check *check, int flag, int i)
{
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return ;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i] || str[i] != ',')
		return ;
	i++;
	if ((!str[i] || !ft_is_space(str[i])) && !ft_isdigit(str[i]))
		return ;
	check_f_c_3(str, check, flag, i);
}

void	check_f_c(char *str, t_check *check, int flag)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_space(str[i]))
		i++;
	i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i] || !ft_isdigit(str[i]))
		return ;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (!str[i] || str[i] != ',')
		return ;
	i++;
	if ((!str[i] || !ft_is_space(str[i])) && !ft_isdigit(str[i]))
		return ;
	check_f_c_2(str, check, flag, i);
}
