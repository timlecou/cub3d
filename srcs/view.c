/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 15:38:43 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 19:53:25 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_color(t_all *all, int i, int size)
{
	all->color = 0;
	if (!ft_is_wall(all->vector.x, all->vector.y, all, 0))
	{
		if (ft_wall_direction(all) == 1)
			ft_west_tex(all, i, size);
		else if (ft_wall_direction(all) == 2)
			ft_east_tex(all, i, size);
		else if (ft_wall_direction(all) == 3)
			ft_north_tex(all, i, size);
		else if (ft_wall_direction(all) == 4)
			ft_south_tex(all, i, size);
	}
}

void	ft_print_column(int index, t_all *all)
{
	int	i;
	int	size;
	int	length;
	int	tmp;

	i = -1;
	length = sqrt(pow(all->vector.x - all->player.x, 2)
	+ pow(all->vector.y - all->player.y, 2));
	if (length == 0)
		length = 1;
	size = 277 * (64 * (all->win.reso_y / 150)) / length;
	tmp = (all->win.reso_y - size) / 2;
	while (++i <= tmp)
		ft_put_image_pixel(all, index, i, all->c_color);
	while (i <= tmp + size)
	{
		get_color(all, i - tmp, size);
		ft_put_image_pixel(all, index, i, all->color);
		i++;
	}
	while (i <= all->win.reso_y)
	{
		ft_put_image_pixel(all, index, i, all->f_color);
		i++;
	}
}
