/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 12:43:06 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 18:07:22 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_pistol(t_all *all)
{
	int	i;
	int	j;
	int	color;

	i = -1;
	while (++i < all->win.reso_x)
	{
		j = -1;
		while (++j < all->win.reso_y)
		{
			color = ft_get_gun_tex(all, i, j);
			if (color != 0x0)
				ft_put_image_pixel(all, i, j, color);
		}
	}
}

void	ft_window(t_all *all)
{
	int		i;
	int		j;

	i = 0;
	while (i < all->win.reso_x / 5)
	{
		j = 0;
		while (j < all->win.reso_y / 5)
		{
			ft_print_minimap_color(all, i, j);
			j++;
		}
		i++;
	}
	ft_print_player(all);
}

void	ft_print_minimap_color(t_all *all, int i, int j)
{
	int	k;
	int	l;

	k = (i * all->map.len) / (all->win.reso_x / 5);
	l = (j * all->map.width) / (all->win.reso_y / 5);
	if (all->map.map[l][k] == '2')
		ft_put_image_pixel(all, i, j, COLOR_SPRITE);
	else if (all->map.map[l][k] == '0')
		ft_put_image_pixel(all, i, j, COLOR_FLOOR);
	else if (ft_is_pos_char(all->map.map[l][k]))
		ft_put_image_pixel(all, i, j, COLOR_SPAWN);
	else
		ft_put_image_pixel(all, i, j, COLOR_WALL);
}
