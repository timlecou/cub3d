/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:29:32 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 20:34:05 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	quit(int flag, char *message)
{
	if (flag == EXIT_FAILURE)
		ft_printf_fd(1, "Error\n%s\n", message);
	else
		ft_printf_fd(1, "%s\n", message);
	exit(flag);
}

int		ft_is_map_part(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
		i++;
	if (i == (int)ft_strlen(str))
		return (0);
	return (1);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf_fd(1, "%s\n", map[i]);
		i++;
	}
}

int		ft_x_p(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map.map[i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (ft_is_pos_char(all->map.map[i][j]))
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_y_p(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map.map[i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (ft_is_pos_char(all->map.map[i][j]))
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}
