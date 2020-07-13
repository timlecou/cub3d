/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:59:28 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 18:06:54 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_go_back(t_all *all)
{
	all->player.x -= rint(cosf(all->player.angle)
	* all->map.wall_len) * SPEED;
	all->player.y -= rint(sinf(all->player.angle)
	* all->map.wall_len) * SPEED;
	ft_print_ray(all);
	ft_display_minimap(all);
}

void	ft_go_left(t_all *all)
{
	all->player.x += rint(cosf(all->player.angle - 1.5708)
	* all->map.wall_len / 2) * SPEED;
	all->player.y += rint(sinf(all->player.angle - 1.5708)
	* all->map.wall_len / 2) * SPEED;
	ft_print_ray(all);
	ft_display_minimap(all);
}

void	ft_go_right(t_all *all)
{
	all->player.x += rint(cosf(all->player.angle + 1.5708)
	* all->map.wall_len / 2) * SPEED;
	all->player.y += rint(sinf(all->player.angle + 1.5708)
	* all->map.wall_len / 2) * SPEED;
	ft_print_ray(all);
	ft_display_minimap(all);
}

void	ft_go_up(t_all *all)
{
	all->player.x += rint(cosf(all->player.angle)
	* all->map.wall_len) * SPEED;
	all->player.y += rint(sinf(all->player.angle)
	* all->map.wall_len) * SPEED;
	ft_print_ray(all);
	ft_display_minimap(all);
}

void	ft_display_minimap(t_all *all)
{
	ft_window(all);
	ft_print_pistol(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
}
