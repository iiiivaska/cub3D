/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:15:50 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 20:43:52 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t count)
{
	unsigned char		*dst;
	const unsigned char	*src;

	dst = (unsigned char *)to;
	src = (unsigned char *)from;
	if (to == 0 && from == 0)
		return (to);
	while (count--)
		*(dst++) = *(src++);
	return (to);
}
