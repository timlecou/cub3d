/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:59:28 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:52:54 by timlecou         ###   ########.fr       */
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
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
}

void	ft_go_left(t_all *all)
{
	all->player.x += rint(cosf(all->player.angle - 1.5708)
	* all->map.wall_len / 2) * SPEED;
	all->player.y += rint(sinf(all->player.angle - 1.5708)
	* all->map.wall_len / 2) * SPEED;
	ft_print_ray(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
}

void	ft_go_right(t_all *all)
{
	all->player.x += rint(cosf(all->player.angle + 1.5708)
	* all->map.wall_len / 2) * SPEED;
	all->player.y += rint(sinf(all->player.angle + 1.5708)
	* all->map.wall_len / 2) * SPEED;
	ft_print_ray(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
}

void	ft_go_up(t_all *all)
{
	all->player.x += rint(cosf(all->player.angle)
	* all->map.wall_len) * SPEED;
	all->player.y += rint(sinf(all->player.angle)
	* all->map.wall_len) * SPEED;
	ft_print_ray(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
}
