/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:28:53 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:21:31 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	file_to_list(t_all *all)
{
	int		fd;
	char	*line;

	fd = open(all->map->path, O_RDONLY);
	if (fd == -1)
		ft_exit(all, 3);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&all->file, ft_lstnew(line));
	ft_lstadd_back(&all->file, ft_lstnew(line));
	close(fd);
}
