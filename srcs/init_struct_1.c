/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 12:34:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:52:11 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_win(t_all *all)
{
	all->win.win = NULL;
	all->win.mlx = NULL;
	all->win.reso_x = 0;
	all->win.max_x = 0;
	all->win.max_y = 0;
	all->win.is_x = -1;
	all->win.is_y = -1;
	all->win.reso_y = 0;
	all->win.midlen = 0;
}

void	ft_init_floor(t_all *all)
{
	all->floor.r = 0;
	all->floor.g = 0;
	all->floor.b = 0;
	all->floor.a = 0;
}

void	ft_init_ceiling(t_all *all)
{
	all->ceiling.r = 0;
	all->ceiling.g = 0;
	all->ceiling.b = 0;
}

void	ft_init_map(t_all *all)
{
	all->map.len = 0;
	all->map.width = 0;
	all->map.pos = 0;
	all->map.wall_len = 0;
	all->map.tmp = ft_strdup("");
}

void	ft_init_player(t_all *all)
{
	all->player.x = 0;
	all->player.y = 0;
	all->player.angle = 0;
	all->player.current_angle = 0;
	all->player.hp = 100;
	all->player.gun.ptr = NULL;
	all->player.gun.data = NULL;
	all->player.gun.width = 0;
	all->player.gun.height = 0;
	all->player.gun.sl = 0;
	all->player.gun.bpp = 0;
	all->player.gun.endian = 0;
}
