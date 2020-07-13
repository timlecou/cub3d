/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:50:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:56:36 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_near_wall(int x, int y, t_all *all)
{
	int	i;
	int	j;

	i = x - 1;
	while (i < x + 1)
	{
		j = y - 1;
		while (j < y + 1)
		{
			if (!ft_is_wall(i, j, all, 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_wall_direction(t_all *all)
{
	if (!ft_is_wall(all->vector.x, all->vector.y, all, 0))
	{
		if (ft_is_wall(all->vector.x + 1, all->vector.y, all, 1))
			return (1);
		else if (ft_is_wall(all->vector.x - 1, all->vector.y, all, 1))
			return (2);
		else if (ft_is_wall(all->vector.x, all->vector.y + 1, all, 1))
			return (3);
		else if (ft_is_wall(all->vector.x + 1, all->vector.y - 1, all, 1))
			return (4);
	}
	return (0);
}

int		ft_sprite_direction(int x, int y, t_all *all)
{
	if (ft_is_sprite(x + 1, y, all))
		return (1);
	else if (ft_is_sprite(x - 1, y, all))
		return (2);
	else if (ft_is_sprite(x, y + 1, all))
		return (3);
	else if (ft_is_sprite(x + 1, y - 1, all))
		return (4);
	return (0);
}

void	ft_put_image_pixel(t_all *all, int x, int y, int color)
{
	if (!(x < 0 || y < 0 || x >= all->win.reso_x || y >= all->win.reso_y))
		all->img.data[x + (y * (all->img.sl / 4))] = color;
}
