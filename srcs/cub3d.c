/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:48:41 by eghis             #+#    #+#             */
/*   Updated: 2021/04/28 12:07:05 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_all	all;

	all.save = 0;
	if (argc == 3 || argc == 2)
	{
		if (argc == 2)
			init_game(argv[1], &all);
		else
		{
			if (check_save(argv[2]))
			{
				all.save = 1;
				init_game(argv[1], &all);
			}
			else
			{
				write(1, "Error\nWrong argument", 20);
				return (0);
			}
		}
	}
	else
		write(1, "Error\nInvalid arguments number", 30);
	return (0);
}
