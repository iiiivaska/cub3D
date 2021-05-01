# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eghis <eghis@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 12:41:10 by eghis             #+#    #+#              #
#    Updated: 2021/04/30 11:01:22 by eghis            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	cub3D

SRCS	=	srcs/cub3d.c \
			srcs/exit/exit.c srcs/exit/clean.c\
			srcs/utils/utils.c\
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			srcs/checkers/check_save.c srcs/checkers/check_colors.c\
			srcs/checkers/check_paths.c srcs/checkers/check.c\
			srcs/checkers/check_cub.c srcs/checkers/check_map.c\
			srcs/checkers/check_file.c srcs/checkers/check_r.c\
			srcs/checkers/check_file_errors.c srcs/checkers/check_texture.c\
			srcs/checkers/check_f_c.c srcs/checkers/check_empty.c\
			srcs/checkers/skip_map.c srcs/checkers/check_map_close.c\
			srcs/core/controller.c srcs/core/init_game.c \
			srcs/core/draw/draw.c srcs/core/draw/draw_scene.c\
			srcs/core/draw/draw_map.c srcs/core/draw/draw_obj.c\
			srcs/core/draw/save.c srcs/core/draw/print_f_c.c\
			srcs/core/draw/find_pix.c srcs/core/draw/my_mlx_pixel_put.c\
			srcs/core/keys/keys.c srcs/core/draw/add_data.c\
			srcs/parsers/file_to_list.c srcs/parsers/parse.c \
			srcs/parsers/parse_flags.c srcs/parsers/parse_f_c.c\
			srcs/parsers/parse_res.c srcs/parsers/parse_texture.c \
			srcs/parsers/parse_map.c srcs/parsers/convert_color.c \
			srcs/parsers/parse_sprites.c srcs/parsers/max_res.c \
			srcs/parsers/get_shaders.c\
			libft/ft_atoi.c libft/ft_calloc.c libft/ft_isdigit.c \
			libft/ft_lstadd_back.c libft/ft_lstnew.c libft/ft_lstsize.c \
			libft/ft_memcpy.c libft/ft_bzero.c libft/ft_lstlast.c

MLX		=	libmlx.dylib

HEADER	=	include/cub3d.h

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

FLAGS	=	-Wall -Wextra -Werror

$(NAME)	:	$(OBJ) $(HEADER)
			$(MAKE) -C minilibx_mms
			@cp minilibx_mms/libmlx.dylib libmlx.dylib
			gcc -o $(NAME) $(MLX) $(OBJ) $(FLAGS)

clean	:	
			$(MAKE) clean -C minilibx_mms
			rm -f $(OBJ)

fclean	:	clean
			@rm -f $(NAME) libmlx.dylib
			$(MAKE) clean -C minilibx_mms

.c.o	:
			gcc $(FLAGS) -c $< -o $@

re		:	fclean all

run		:	all clean
			./cub3d maps/simple_valid_map_1.cub

.PHONY	: all clean fclean re bonus
