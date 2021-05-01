/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 18:34:43 by eghis             #+#    #+#             */
/*   Updated: 2021/04/26 17:20:02 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

void	ft_add_img(t_all *all, char *bmp)
{
	long long int	d;
	long long int	d_f;
	int				x;
	int				y;

	x = 0;
	while (x < all->map->width)
	{
		y = 0;
		while (y < all->map->height)
		{
			d_f = (y * all->map->width + x) * (all->win->bpp / 8);
			d = y * all->win->linel + x * (all->win->bpp / 8);
			*(unsigned int *)(bmp + 54 + d_f) = *((unsigned int *)
					(all->win->addr + d));
			y++;
		}
		x++;
	}
}

void	ft_add_info(t_all *all, char *bmp, long long int size, long long int i)
{
	ft_memcpy(&bmp[0], "BM", 2);
	ft_memcpy(&bmp[2], &size, 4);
	ft_memcpy(&bmp[6], &i, 2);
	i = 54;
	ft_memcpy(&bmp[10], &i, 4);
	i = 40;
	ft_memcpy(&bmp[14], &i, 4);
	i = all->map->width;
	ft_memcpy(&bmp[18], &i, 4);
	i = -all->map->height;
	ft_memcpy(&bmp[22], &i, 4);
	i = 1;
	ft_memcpy(&bmp[26], &i, 2);
	i = 32;
	ft_memcpy(&bmp[28], &i, 2);
	i = 0;
	ft_memcpy(&bmp[30], &i, 4);
	i = 0;
	ft_memcpy(&bmp[34], &i, 4);
	i = 2855;
	ft_memcpy(&bmp[38], &i, 4);
	ft_memcpy(&bmp[42], &i, 4);
	i = 0;
	ft_memcpy(&bmp[46], &i, 4);
	ft_memcpy(&bmp[50], &i, 4);
}

void	ft_save(t_all *all)
{
	char			*bmp;
	long long int	size;
	long long int	i;

	i = 0;
	size = all->map->height * all->map->width * (all->win->bpp / 8) + 54;
	bmp = ft_calloc(1, size);
	if (!bmp)
		ft_exit(all, 3);
	ft_add_info(all, bmp, size, i);
	ft_add_img(all, bmp);
	i = open("cub3D.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (!i)
	{
		all->error = "Can't write image";
		ft_exit(all, 2);
	}
	if ((write(i, bmp, size)) < 0)
	{
		all->error = "Can't write image";
		ft_exit(all, 2);
	}
	close(i);
	free(bmp);
	ft_exit(all, 1);
}
