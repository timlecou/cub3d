/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 10:45:46 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:55:59 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_west_tex(t_all *all, int i, int size)
{
	int	k;
	int	l;

	k = (all->vector.y % 64 * all->tex.i_we.height) / 64;
	l = (i * all->tex.i_we.height) / size;
	if (k < 0 || l < 0 || k > all->tex.i_we.width || l >
	all->tex.i_we.height || k + (l * (all->tex.i_we.sl / 4))
	>= (all->tex.i_we.width * all->tex.i_we.height))
		all->color = 0x0;
	else
		all->color = (all->tex.i_we.data[k + (l *
		(all->tex.i_we.sl / 4))]);
}

void	ft_south_tex(t_all *all, int i, int size)
{
	int	k;
	int	l;

	k = (all->vector.x % 64 * all->tex.i_so.height) / 64;
	l = (i * all->tex.i_so.height) / size;
	if (k < 0 || l < 0 || k > all->tex.i_so.width || l >
	all->tex.i_so.height || k + (l * (all->tex.i_so.sl / 4))
	>= (all->tex.i_so.width * all->tex.i_so.height))
		all->color = 0x0;
	else
		all->color = (all->tex.i_so.data[k + (l *
		(all->tex.i_we.sl / 4))]);
}

void	ft_north_tex(t_all *all, int i, int size)
{
	int	k;
	int	l;

	k = (all->vector.x % 64 * all->tex.i_no.height) / 64;
	l = (i * all->tex.i_no.height) / size;
	if (k < 0 || l < 0 || k > all->tex.i_no.width || l >
	all->tex.i_no.height || k + (l * (all->tex.i_no.sl / 4))
	>= (all->tex.i_no.width * all->tex.i_no.height))
		all->color = 0x0;
	else
		all->color = (all->tex.i_no.data[k + (l *
		(all->tex.i_no.sl / 4))]);
}

void	ft_east_tex(t_all *all, int i, int size)
{
	int	k;
	int	l;

	k = (all->vector.y % 64 * all->tex.i_ea.height) / 64;
	l = (i * all->tex.i_ea.height) / size;
	if (k < 0 || l < 0 || k > all->tex.i_ea.width || l >
	all->tex.i_ea.height || k + (l * (all->tex.i_ea.sl / 4))
	>= (all->tex.i_ea.width * all->tex.i_ea.height))
		all->color = 0x0;
	else
		all->color = (all->tex.i_ea.data[k + (l *
		(all->tex.i_ea.sl / 4))]);
}

void	ft_sprite_tex(t_all *all, int l, int j, int index)
{
	if (index < 0 || l < 0 || index > all->sprites[j].tex.width
	|| l > all->sprites[j].tex.height || index + (l *
	(all->sprites[j].tex.sl / 4)) >= (all->sprites[j].tex.width
	* all->sprites[j].tex.height))
		all->color = 0x0;
	else
		all->color = (all->sprites[j].tex.data[index +
		(l * (all->sprites[j].tex.sl / 4))]);
}
