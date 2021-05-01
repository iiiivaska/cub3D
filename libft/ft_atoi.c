/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:35:57 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 12:59:52 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INT_MAX 2147483647

static int	is_space(char ch)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f'
		|| ch == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	unsigned long	num;
	int				flag;

	flag = 1;
	num = 0;
	while (is_space(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag *= -1;
		s++;
	}
	while (*s >= 48 && *s <= 57)
	{
		if (num > INT_MAX && flag == 1)
			return (INT_MAX);
		if (num > (long)INT_MAX + 1 && flag == -1)
			return (0);
		num = num * 10 + (*s - 48);
		s++;
	}
	return ((int)(num * flag));
}
