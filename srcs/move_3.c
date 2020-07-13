/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:43:38 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:53:09 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_core(t_all *all)
{
	if (all->key[K_RIGHT] == 1)
		ft_turn_right(all);
	if (all->key[K_LEFT] == 1)
		ft_turn_left(all);
	if (all->key[K_DOWN] == 1 && ft_near_down(all))
		ft_go_back(all);
	if (all->key[K_UP] == 1 && ft_near_up(all))
		ft_go_up(all);
	if (all->key[K_GO_RIGHT] == 1 && ft_near_right(all))
		ft_go_right(all);
	if (all->key[K_GO_LEFT] == 1 && ft_near_left(all))
		ft_go_left(all);
	if (all->key[K_ESC] == 1)
		quit(EXIT_SUCCESS, CLOSE_GAME);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
	return (0);
}

int		ft_near_down(t_all *all)
{
	int	x;
	int	y;

	x = all->player.x - (rint(cosf(all->player.angle)
	* all->map.len) * SPEED);
	y = all->player.y - (rint(sinf(all->player.angle)
	* all->map.len) * SPEED);
	return (ft_is_in_map(all, x, y));
}

int		ft_hit_key(int key, t_all *all)
{
	all->key[key] = 1;
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
	return (0);
}

int		ft_release_key(int key, t_all *all)
{
	all->key[key] = 0;
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
	return (0);
}
