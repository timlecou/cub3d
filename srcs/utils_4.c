/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:55:11 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:56:46 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_add_line(char *line)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (!(res = (char*)malloc(sizeof(char) * (int)ft_strlen(line) - i + 1)))
		return (NULL);
	while (line[i] != '\0')
	{
		res[j] = line[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	ft_print_player(t_all *all)
{
	int	k;
	int	l;
	int	len;

	len = all->win.reso_x / 42;
	k = ((all->player.x + 64) * all->win.reso_x /
	(all->map.len * 64) - len) / 5;
	l = ((all->player.y + 64) * all->win.reso_y /
	(all->map.width * 64) - len) / 5;
	while (k < ((all->player.x + 64) * all->win.reso_x
	/ (all->map.len * 64) + len) / 5)
	{
		l = ((all->player.y + 64) * all->win.reso_y /
		(all->map.width * 64) - len) / 5;
		while (l < ((all->player.y + 64) * all->win.reso_y
		/ (all->map.width * 64) + len) / 5)
		{
			if (k < all->win.reso_x && l < all->win.reso_y)
				ft_put_image_pixel(all, k, l, COLOR_PLAYER);
			l++;
		}
		k++;
	}
}

int		ft_is_sprite(int x, int y, t_all *all)
{
	int	k;
	int	l;

	l = (x % 64 > 0) ? (x / 64) + 1 : (x / 64);
	k = (y % 64 > 0) ? (y / 64) + 1 : (y / 64);
	if (!&all->map.map[k][l])
		return (1);
	if (all->map.map[k][l] == '2')
		return (0);
	return (1);
}

int		get_pixel(t_all *all, int x, int y)
{
	if (x < 0 || y < 0)
		return (0x0);
	return (all->img.data[x + (y * (all->img.sl / 4))]);
}

int		ft_get_gun_tex(t_all *all, int i, int j)
{
	int	k;
	int	l;

	k = i * all->player.gun.width / all->win.reso_x;
	l = j * all->player.gun.height / all->win.reso_y;
	if (k < 0 || l < 0 || k + (l * (all->player.gun.sl / 4))
	>= (all->player.gun.width * all->player.gun.height) ||
	k > all->player.gun.width || l > all->player.gun.height)
		return (0x0);
	else
		return (all->player.gun.data[k + (l * (all->player.gun.sl
		/ 4))]);
}
