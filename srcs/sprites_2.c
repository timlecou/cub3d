/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:50:01 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 21:50:39 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sort_sprite_tab(t_all *all)
{
	t_sprite	elem;
	int			i;
	int			j;

	i = 0;
	while (i < all->sprite_nb)
	{
		j = i + 1;
		while (j < all->sprite_nb)
		{
			if (all->sprites[i].dist < all->sprites[j].dist)
			{
				elem = all->sprites[i];
				all->sprites[i] = all->sprites[j];
				all->sprites[j] = elem;
			}
			j++;
		}
		i++;
	}
}

void	ft_sprite_column(t_all *all, int j, int l, int m)
{
	int	i;
	int	size;
	int	tmp;
	int	para;

	i = 0;
	size = (277 * (64 * (all->win.reso_y / 150))) / all->sprites[m].dist;
	tmp = (all->win.reso_y - size) / 2;
	i = tmp;
	while (i <= tmp + size)
	{
		para = ((i - tmp) * all->sprites[m].tex.height) / size;
		ft_sprite_tex(all, para, m, l);
		if (all->color != 0x0)
			ft_put_image_pixel(all, all->sprites[m].ray + j, i, all->color);
		i++;
	}
}

void	ft_put_sprite(t_all *all, int i)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	k = all->sprites[i].count;
	if (all->sprites[i].max_ray <= 0)
		l = ((all->sprites[i].ray +
		abs(all->sprites[i].max_ray)) *
		all->sprites[i].tex.width) / all->sprites[i].max_count;
	else
		l = ((all->sprites[i].ray -
		all->sprites[i].max_ray) *
		all->sprites[i].tex.width) / all->sprites[i].max_count;
	while (j < k)
	{
		ft_sprite_column(all, j, l, i);
		l = ((all->sprites[i].ray + j -
		all->sprites[i].max_ray) *
		all->sprites[i].tex.width) / all->sprites[i].max_count;
		j++;
	}
}

void	ft_print_sprites(t_all *all)
{
	int	i;

	i = 0;
	while (all->sprites[i].init == 1 && i < all->sprite_nb)
	{
		ft_put_sprite(all, i);
		i++;
	}
}
