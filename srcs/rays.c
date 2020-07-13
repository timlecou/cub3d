/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:41:39 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 19:54:13 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_ray(t_all *all)
{
	float	an;
	float	op;
	int		i;

	i = 0;
	ft_init_sprite_tab(all);
	op = all->player.angle - 0.523599;
	an = 1.0472 / (float)all->win.reso_x;
	while (op <= all->player.angle + 0.523599)
	{
		ft_ray(all, op, i);
		all->current_angle = op;
		if (all->vector.x != all->player.x || all->vector.y
		!= all->player.y)
			ft_print_column(i, all);
		op += an;
		i++;
	}
	ft_sort_sprite_tab(all);
	ft_sprite_casting(all);
	ft_print_sprites(all);
}

int		ft_sp_is_set(t_all *all, int x, int y, int j)
{
	int	i;

	i = 0;
	while (i < all->sprite_nb)
	{
		if (all->sprites[i].x == x && all->sprites[i].y == y)
		{
			if (all->sprites[i].b == 0)
			{
				all->sprites[i].count++;
				all->sprites[i].last_ray = j;
				all->sprites[i].b = 1;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_find_sp_index(t_all *all)
{
	int	i;

	i = 0;
	while (all->sprites[i].init == 1 && i < all->sprite_nb)
		i++;
	return (i);
}

void	ft_set_in_sprite(t_all *all, int x_p, int y_p, int j)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = (x_p % 64 > 0) ? (x_p / 64) + 1 : (x_p / 64);
	x = x * 64 - 32;
	y = (y_p % 64 > 0) ? (y_p / 64) + 1 : (y_p / 64);
	y = y * 64 - 32;
	if (!ft_sp_is_set(all, x, y, j))
	{
		i = ft_find_sp_index(all);
		all->sprites[i].x = x;
		all->sprites[i].y = y;
		all->sprites[i].hit_x = x_p;
		all->sprites[i].hit_y = y_p;
		all->sprites[i].ray = j;
		all->sprites[i].dist = sqrt(pow(all->sprites[i].x
		- all->player.x, 2) + pow(all->sprites[i].y - all->player.y, 2));
		all->sprites[i].init = 1;
	}
}

void	ft_ray(t_all *all, float op, int j)
{
	int	x_p;
	int	y_p;
	int	a;

	x_p = all->player.x;
	y_p = all->player.y;
	a = 1;
	ft_init_sprite_b(all);
	while (ft_is_wall(x_p, y_p, all, 0) || !ft_is_sprite(x_p, y_p, all))
	{
		x_p = (int)(cosf(op) * a) + all->player.x;
		y_p = (int)(sinf(op) * a) + all->player.y;
		a++;
		if (!ft_is_sprite(x_p, y_p, all))
			ft_set_in_sprite(all, x_p, y_p, j);
	}
	all->vector.x = x_p;
	all->vector.y = y_p;
}
