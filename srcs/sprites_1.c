/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:42:38 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:55:29 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_this_sprite(int id_sp, t_all *all, float op)
{
	int	x;
	int	y;
	int	x_r;
	int	y_r;
	int	a;

	x = all->player.x;
	y = all->player.y;
	x_r = 0;
	y_r = 0;
	a = 1;
	while (x < all->map.len * 64 && a++ && x >= 0 && y < all->map.width * 64
	&& y >= 0 && (x_r != all->sprites[id_sp].x
	|| y_r != all->sprites[id_sp].y))
	{
		x = (int)(cosf(op) * a) + all->player.x;
		y = (int)(sinf(op) * a) + all->player.y;
		x_r = (x % 64 > 0) ? (x / 64) + 1 : (x / 64);
		x_r = x_r * 64 - 32;
		y_r = (y % 64 > 0) ? (y / 64) + 1 : (y / 64);
		y_r = y_r * 64 - 32;
	}
	if (x_r == all->sprites[id_sp].x && y_r == all->sprites[id_sp].y)
		return (1);
	return (0);
}

void	ft_sprite_ray2(t_all *all, int i, float op, int id_sp)
{
	all->sprites[id_sp].max_count++;
	if (all->sprites[id_sp].is_ray == 0)
	{
		all->sprites[id_sp].max_ray = i;
		all->sprites[id_sp].is_ray = 1;
	}
	if (i == 0)
	{
		while (ft_is_this_sprite(id_sp, all, op))
		{
			all->sprites[id_sp].max_count++;
			all->sprites[id_sp].max_ray--;
			op -= 1.0472 / (float)all->win.reso_x;
		}
		i++;
	}
	if (i == all->win.reso_x - 1)
	{
		while (ft_is_this_sprite(id_sp, all, op))
		{
			all->sprites[id_sp].max_count++;
			op += 1.0472 / (float)all->win.reso_x;
		}
	}
}

void	ft_sprite_ray(t_all *all, float op, int id_sp, int i)
{
	int	x;
	int	y;
	int	x_r;
	int	y_r;
	int	a;

	x = all->player.x;
	y = all->player.y;
	x_r = 0;
	y_r = 0;
	a = 1;
	while (x < all->map.len * 64 && a++ && x >= 0 && y < all->map.width * 64
	&& y >= 0 && (x_r != all->sprites[id_sp].x
	|| y_r != all->sprites[id_sp].y))
	{
		x = (int)(cosf(op) * a) + all->player.x;
		y = (int)(sinf(op) * a) + all->player.y;
		x_r = (x % 64 > 0) ? (x / 64) + 1 : (x / 64);
		x_r = x_r * 64 - 32;
		y_r = (y % 64 > 0) ? (y / 64) + 1 : (y / 64);
		y_r = y_r * 64 - 32;
	}
	if (x_r == all->sprites[id_sp].x
	&& y_r == all->sprites[id_sp].y)
		ft_sprite_ray2(all, i, op, id_sp);
}

void	ft_print_sprite_ray(t_all *all, int index)
{
	float	an;
	float	op;
	int		i;

	i = 0;
	op = all->player.angle - 0.523599;
	an = 1.0472 / (float)all->win.reso_x;
	while (op <= all->player.angle + 0.523599)
	{
		ft_sprite_ray(all, op, index, i);
		op += an;
		i++;
	}
}

void	ft_sprite_casting(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->sprite_nb)
	{
		if (!ft_player_in_sprite(all, i) && all->sprites[i].init == 1)
			ft_print_sprite_ray(all, i);
		i++;
	}
}
