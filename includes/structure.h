/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:44:13 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 21:42:19 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include "cub3d.h"

typedef	struct	s_image
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;
	int			bpp;
	int			sl;
	int			endian;
}				t_image;

typedef struct	s_player
{
	int			x;
	int			y;
	int			hp;
	float		angle;
	float		current_angle;
	t_image		gun;
}				t_player;

typedef struct	s_map
{
	char		**map;
	char		*tmp;
	int			len;
	int			width;
	char		pos;
	int			wall_len;
}				t_map;

typedef struct	s_color
{
	uint64_t	r;
	uint64_t	g;
	uint64_t	b;
	uint64_t	a;
}				t_color;

typedef	struct	s_tex
{
	char		*no;
	t_image		i_no;
	char		*so;
	t_image		i_so;
	char		*ea;
	t_image		i_ea;
	char		*we;
	t_image		i_we;
	char		*sp;
	t_image		i_sp;
}				t_tex;

typedef	struct	s_win
{
	void		*win;
	void		*mlx;
	int			reso_x;
	int			reso_y;
	int			is_x;
	int			is_y;
	int			max_x;
	int			max_y;
	int			midlen;
}				t_win;

typedef	struct	s_vector
{
	int			x;
	int			y;
}				t_vector;

typedef	struct	s_sprite
{
	int			x;
	int			y;
	int			hit_x;
	int			hit_y;
	int			ray;
	int			is_ray;
	int			last_ray;
	int			max_ray;
	int			b;
	int			dist;
	int			start;
	int			count;
	int			max_count;
	int			init;
	t_image		tex;
}				t_sprite;

typedef struct	s_all
{
	int			all;
	int			save;
	int			color;
	int			f_color;
	int			c_color;
	int			sprite_nb;
	float		current_angle;
	int			key[500];
	t_win		win;
	t_tex		tex;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_player	player;
	t_vector	vector;
	t_image		img;
	t_sprite	*sprites;
}				t_all;
#endif
