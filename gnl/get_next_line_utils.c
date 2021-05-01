/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:07:03 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 20:52:15 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_nl(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*final;
	int		ss1;
	int		ss2;
	int		i;

	i = 0;
	ss1 = ft_strlen(str1);
	ss2 = ft_strlen(str2);
	final = (char *)malloc(sizeof(char) * (ss1 + ss2 + 1));
	if (!final)
		return (0);
	while (ss1--)
	{
		final[i] = str1[i];
		i++;
	}
	while (*str2)
		final[i++] = *str2++;
	final[i] = '\0';
	free((void *)str1);
	return (final);
}
