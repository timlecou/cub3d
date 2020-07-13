/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 11:30:56 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:57:07 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_pos_char(char c)
{
	if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		return (1);
	return (0);
}

int		ft_is_map_char(char c)
{
	if (c == ' ' || c == '1' || c == '2'
	|| c == '0' || ft_is_pos_char(c))
		return (1);
	return (0);
}

int		ft_nl_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	ft_set_player_pos(t_all *all)
{
	if (all->map.pos == 'S')
		all->player.angle = M_PI / 2;
	else if (all->map.pos == 'E')
		all->player.angle = 2 * M_PI;
	else if (all->map.pos == 'N')
		all->player.angle = 3 * (M_PI / 2);
	else if (all->map.pos == 'W')
		all->player.angle = M_PI;
}

int		ft_check_check_map(t_all *all, int i, int j)
{
	if (!ft_is_map_char(all->map.map[i][j]))
		return (0);
	if ((i == 0 || j == 0) && (all->map.map[i][j] !=
	'1' && all->map.map[i][j] != ' '))
		return (1);
	if (all->map.map[i][j] == '0' || all->map.map[i][j] == '2')
	{
		if (i != 0 && j != 0)
			if (!(ft_check_unclosed(all->map.map, i, j)))
				return (1);
		if (j + 1 == (int)ft_strlen(all->map.map[i]))
			return (1);
	}
	return (-1);
}
