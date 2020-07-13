/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:37:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:56:57 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_side(char **map, int i, int j)
{
	int	x;

	x = 0;
	if (i == 0 || j == 0)
		return (0);
	while (map[i - 1 + x] && x < 3)
	{
		if (!map[i - 1 + x][j - 1] || map[i - 1 + x][j - 1] == ' ')
			return (0);
		if (!map[i - 1 + x][j] || map[i - 1 + x][j] == ' ')
			return (0);
		if (!map[i - 1 + x][j + 1] || map[i - 1 + x][j + 1] == ' ')
			return (0);
		x++;
	}
	return (1);
}

int		ft_is_in_map(t_all *all, int x_r, int y_r)
{
	int	x;
	int	y;

	y = (x_r % 64 > 0) ? (x_r / 64) + 1
	: (x_r / 64);
	x = (y_r % 64 > 0) ? (y_r / 64) + 1
	: (y_r / 64);
	if (y_r <= 64 || y_r >= (all->map.width - 1) * 64)
		return (0);
	if (x_r <= 64 || x_r >= (all->map.len - 1) * 64)
		return (0);
	if (y >= (int)ft_strlen(all->map.map[x]))
		return (0);
	if (all->map.map[x][y] == '\0' || all->map.map[x][y] == ' ')
		return (0);
	if (!(all->map.map[x][y] == '1' || all->map.map[x][y] == '0'
	|| all->map.map[x][y] == '2' || ft_is_pos_char(all->map.map[x][y])))
		if (ft_is_side(all->map.map, x, y))
			return (0);
	return (1);
}

int		ft_player_in_sprite(t_all *all, int i)
{
	int	x;
	int	y;
	int	x_s;
	int	y_s;

	x = (all->player.x % 64 > 0) ? (all->player.x / 64) + 1
	: (all->player.x / 64);
	y = (all->player.y % 64 > 0) ? (all->player.y / 64) + 1
	: (all->player.y / 64);
	x_s = (all->sprites[i].x % 64 > 0) ? (all->sprites[i].x / 64) + 1
	: (all->sprites[i].x / 64);
	y_s = (all->sprites[i].y % 64 > 0) ? (all->sprites[i].y / 64) + 1
	: (all->sprites[i].y / 64);
	if (x == x_s && y == y_s)
	{
		all->sprites[i].init = 0;
		return (1);
	}
	return (0);
}
