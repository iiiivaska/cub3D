/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghis <eghis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:50:14 by eghis             #+#    #+#             */
/*   Updated: 2021/04/30 11:05:42 by eghis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_mms/mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# define ESC 53
# define TOWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define CAM_LEFT 123
# define CAM_RIGHT 124
# define SCALE 60
# define MINI_MAP 10
# define SPEED 10
# define MLX_SYNC_IMAGE_WRITABLE    1
# define MLX_SYNC_WIN_FLUSH_CMD     2
# define MLX_SYNC_WIN_CMD_COMPLETED 3

typedef struct s_ray
{
	float	x;
	float	y;
	float	dir;
	float	len;
	char	text;
	int		*lenght;
	double	*direct;
}				t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	color;
}				t_color;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		linel;
	int		bpp;
	int		en;
}				t_win;

typedef struct s_plr
{
	float	x;
	float	y;
	float	dir;
}				t_plr;

typedef struct s_map
{
	char	*path;
	char	**map;
	int		row;
	int		width;
	int		height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	t_color	*f;
	t_color	*c;
}				t_map;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_sp
{
	int		x;
	int		y;
	int		x_2;
	int		y_2;
	double	dir;
	double	dir_p;
	double	len;
	double	size;
	double	size_2;
	int		x_sc;
	int		y_sc;
	double	s;
}				t_sp;

typedef struct s_shader
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			l_l;
	int			end;
}				t_shader;

typedef struct s_sprite
{
	int			count;
	t_sp		**p;
	void		*img;
	char		*addr;
	int			width;
	int			height;
	double		w_s;
	double		h_s;
	int			bpp;
	int			l_l;
	int			end;
}				t_sprite;

typedef struct s_all
{
	char		*error;
	t_list		*file;
	t_win		*win;
	t_map		*map;
	t_plr		*plr;
	t_ray		*ray;
	t_shader	*no;
	t_shader	*we;
	t_shader	*ea;
	t_shader	*so;
	t_sprite	*s;
	int			save;
	int			m;
	int			trian;
	int			trian_2;
	int			color;
	int			i;
}				t_all;

typedef struct s_check
{
	int			r;
	int			no;
	int			we;
	int			so;
	int			ea;
	int			s;
	int			f;
	int			c;
	int			trash;
}				t_check;

int				find_pix_2(t_all *all, int n_x, int n_y);
int				ft_atoi(const char *s);
void			*ft_calloc(size_t number, size_t size);
int				ft_isdigit(int character);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memcpy(void *to, const void *from, size_t count);
void			ft_bzero(void *s, size_t n);
t_list			*ft_lstlast(t_list *lst);
int				check_save(char *str);
int				ft_is_space(char ch);
int				find_pix(t_all *all, int size, int n_y);
int				key_press(int key, t_all *all);
int				ft_isempty(char *str);
void			init_game(char *path, t_all *all);
void			controller(t_all *all);
void			parse(t_all *all);
void			file_to_list(t_all *all);
void			ft_exit(t_all *all, int	flag);
int				ft_exit_2(t_all *all);
void			parse_flags(t_all *all);
void			parse_res(t_all *all, char *str);
void			parse_texture(t_all *all, char *str, int flag);
void			parse_f_c(t_all *all, char *str, int flag);
void			map_parcer(t_all *all, t_list **head);
void			convert_color(t_all *all);
void			parse_sprites(t_all *all);
void			max_res(t_all *all);
void			get_shaders(t_all *all);
void			draw(t_all *all);
void			draw_scene(t_all *all);
void			draw_map(t_all *all);
void			draw_obj(t_all *all);
void			ft_save(t_all *all);
void			print_ceiling(t_all *all, int start, int k);
void			print_floor(t_all *all, int start, int k);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
void			clean(t_all *all);
void			check_colors(t_all *all);
void			check(t_all *all);
void			check_paths(t_all *all);
void			check_cub(t_all *all);
void			check_map(t_all *all);
void			check_file(t_all *all);
void			check_r(char *str, t_check *check);
void			check_file_errors(t_all *all, t_check *check);
void			check_texture(char *str, int flag, t_check *check);
void			check_f_c(char *str, t_check *check, int flag);
void			check_empty(char *str, t_check *check);
void			check_close(t_all *all, int x, int y);
void			add_data(t_all *all, int i);
t_list			*skip_map(t_list *head);
#endif
