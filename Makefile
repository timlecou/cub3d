# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timlecou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 09:45:09 by timlecou          #+#    #+#              #
#    Updated: 2020/06/26 20:57:11 by timlecou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/cub3d.c srcs/utils_parsing.c srcs/get_next_line.c\
	   srcs/get_next_line_utils.c srcs/parsing_1.c srcs/parse_textures.c\
	   srcs/init_struct_1.c srcs/init_struct_2.c srcs/utils_1.c\
	   srcs/utils_3.c srcs/parsing_2.c srcs/rays.c\
	   srcs/view.c srcs/textures_1.c srcs/init_struct_3.c srcs/sprites_1.c\
	   srcs/save_image.c srcs/check_parsing.c srcs/utils_parsing_2.c\
	   srcs/rays_2.c srcs/sprites_2.c srcs/utils_4.c srcs/parsing_3.c\
	   srcs/parsing_4.c srcs/utils_5.c

SRCS2 = srcs/move_1.c srcs/move_2.c srcs/move_3.c srcs/utils_2.c

SRCSBONUS = bonus/utils_bonus.c bonus/move_1_bonus.c bonus/move_2_bonus.c\
			bonus/utils_2_bonus.c bonus/move_3_bonus.c

NAME = Cub3D

FLAGS = -Werror -Wextra -Wall

INCLUDES = mlx

FRAMEWORK = -framework OpenGL -framework AppKit

COMPIL = gcc

all:
	make -C libft all
	$(COMPIL) $(FLAGS) libft/libft.a -I $(INCLUDES) $(SRCS) $(SRCS2) -L $(INCLUDES) -lmlx $(FRAMEWORK) -o $(NAME)

$(NAME): all

bonus:
	make -C libft all
	$(COMPIL) $(FLAGS) libft/libft.a -I $(INCLUDES) $(SRCS) $(SRCSBONUS) -L $(INCLUDES) -lmlx $(FRAMEWORK) -o $(NAME)


clean:
	make -C libft clean

fclean:
	/bin/rm $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re Cub3D
