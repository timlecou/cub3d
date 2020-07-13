/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:39:47 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 21:56:06 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_map(t_all *all)
{
	int	i;
	int	j;
	int	pos;

	i = -1;
	pos = 0;
	while (all->map.map[++i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (ft_check_check_map(all, i, j) > -1)
				return (ft_check_check_map(all, i, j));
			if (ft_is_pos_char(all->map.map[i][j]))
			{
				all->map.pos = all->map.map[i][j];
				pos++;
			}
			j++;
		}
	}
	if (pos != 1)
		return (2);
	ft_set_player_pos(all);
	return (3);
}

void	ft_free_t_all(t_all *all)
{
	int	i;

	i = 0;
	free(all->tex.no);
	free(all->tex.so);
	free(all->tex.ea);
	free(all->tex.we);
	free(all->tex.sp);
	while (all->map.map[i])
	{
		free(all->map.map[i]);
		i++;
	}
	free(all->map.map);
	free(all->key);
}

void	ft_check_color_2(char *str)
{
	int	i;

	i = 0;
	while (!ft_isdigit(str[i]) && str[i] != '\0')
	{
		if (str[i] == ',')
			quit(EXIT_FAILURE, CANT_GET_COLOR);
		i++;
	}
	while (ft_isdigit(str[i]) && str[i] != '\0')
		i++;
	while (str[i - 1] != ',' && str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			quit(EXIT_FAILURE, CANT_GET_COLOR);
		i++;
	}
}
