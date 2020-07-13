/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:58:10 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 18:06:45 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_near_up(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x + (rint(cosf(all->player.angle)
	* all->map.len) * SPEED);
	y = all->player.y + (rint(sinf(all->player.angle)
	* all->map.len) * SPEED);
	return (ft_is_wall(x, y, all, 0));
}

int		ft_near_right(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x + (rint(cosf(all->player.angle + 1.5708)
	* all->map.len) * SPEED);
	y = all->player.y + (rint(sinf(all->player.angle + 1.5708)
	* all->map.len) * SPEED);
	return (ft_is_wall(x, y, all, 0));
}

int		ft_near_left(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x + (rint(cosf(all->player.angle - 1.5708)
	* all->map.len) * SPEED);
	y = all->player.y + (rint(sinf(all->player.angle - 1.5708)
	* all->map.len) * SPEED);
	return (ft_is_wall(x, y, all, 0));
}

void	ft_turn_left(t_all *all)
{
	all->player.angle -= 0.0174533 * SENSI;
	ft_print_ray(all);
	ft_display_minimap(all);
}

void	ft_turn_right(t_all *all)
{
	all->player.angle += 0.0174533 * SENSI;
	ft_print_ray(all);
	ft_display_minimap(all);
}
