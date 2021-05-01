/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:06:02 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:09:10 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_list	*skip_map(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (temp && !ft_isempty(temp->content))
	{
		temp = temp->next;
	}
	return (temp);
}
