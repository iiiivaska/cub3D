/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:04:32 by eghis             #+#    #+#             */
/*   Updated: 2021/04/29 20:46:23 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_shader	*init_shader(t_shader *shader)
{
	shader->img = 0;
	shader->addr = 0;
	shader->width = 0;
	shader->height = 0;
	shader->bpp = 0;
	shader->l_l = 0;
	shader->end = 0;
	return (shader);
}

void	init_game_3(t_all *all)
{
	t_sprite	sprite;

	sprite.count = 0;
	sprite.p = 0;
	sprite.img = 0;
	sprite.addr = 0;
	sprite.width = 0;
	sprite.height = 0;
	sprite.bpp = 0;
	sprite.l_l = 0;
	sprite.end = 0;
	all->s = &sprite;
	all->file = 0;
	all->ray->direct = 0;
	all->color = 0;
	check_cub(all);
	controller(all);
}

void	init_game_2(t_all *all)
{
	t_ray		ray;
	t_shader	no;
	t_shader	ea;
	t_shader	we;
	t_shader	so;

	all->no = init_shader(&no);
	all->ea = init_shader(&ea);
	all->we = init_shader(&we);
	all->so = init_shader(&so);
	ray.x = 0;
	ray.y = 0;
	ray.dir = 0;
	ray.len = 0;
	ray.text = 0;
	ray.lenght = 0;
	all->ray = &ray;
	init_game_3(all);
}

void	init_game(char *path, t_all *all)
{
	t_win	win;
	t_plr	plr;
	t_map	map;

	map.path = path;
	map.width = 0;
	map.height = 0;
	map.map = 0;
	map.no = 0;
	map.so = 0;
	map.we = 0;
	map.ea = 0;
	map.s = 0;
	map.f = 0;
	map.c = 0;
	win.mlx = 0;
	win.win = 0;
	win.img = 0;
	plr.dir = 0;
	plr.x = 0;
	plr.y = 0;
	all->map = &map;
	all->plr = &plr;
	all->win = &win;
	init_game_2(all);
}
