/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:25:06 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:52:21 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_t_all(t_all *all)
{
	all->all = 0;
	all->color = 0;
	all->save = 0;
	all->f_color = 0;
	all->c_color = 0;
	all->sprite_nb = 0;
	all->current_angle = 0;
	ft_bzero(all->key, sizeof(int) * 256);
	ft_init_win(all);
	ft_init_tex(all);
	ft_init_floor(all);
	ft_init_ceiling(all);
	ft_init_map(all);
	ft_init_player(all);
	ft_init_vector(all);
	ft_init_img(all);
}

void	ft_init_tex(t_all *all)
{
	all->tex.no = NULL;
	all->tex.i_no.ptr = NULL;
	all->tex.i_no.width = 0;
	all->tex.i_no.height = 0;
	all->tex.i_so.ptr = NULL;
	all->tex.i_so.width = 0;
	all->tex.i_so.height = 0;
	all->tex.i_ea.ptr = NULL;
	all->tex.i_ea.width = 0;
	all->tex.i_ea.height = 0;
	all->tex.i_we.ptr = NULL;
	all->tex.i_we.width = 0;
	all->tex.i_we.height = 0;
	all->tex.i_sp.ptr = NULL;
	all->tex.i_sp.width = 0;
	all->tex.i_sp.height = 0;
	all->tex.so = NULL;
	all->tex.ea = NULL;
	all->tex.we = NULL;
	all->tex.sp = NULL;
}

void	ft_init_pos(t_all *all)
{
	all->player.x = ft_y_p(all) * 64 - 32;
	all->player.y = ft_x_p(all) * 64 - 32;
}

void	ft_init_img(t_all *all)
{
	all->img.ptr = NULL;
	all->img.data = NULL;
	all->img.bpp = 0;
	all->img.sl = 0;
	all->img.endian = 0;
}
