/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 10:05:36 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 21:55:28 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_reso_valid(char *str)
{
	int	i;
	int	a;

	i = 1;
	a = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && !ft_isdigit(str[i])) || a > 2)
			return (0);
		if (ft_isdigit(str[i]))
		{
			a++;
			while (ft_isdigit(str[i]))
				i++;
			i--;
		}
		i++;
	}
	if (a > 2)
		return (0);
	return (1);
}

char	*get_val(char *line, char *key)
{
	char	*tmp;

	if (!key || !line)
		return (0);
	if ((tmp = ft_strnstr(line, key, ft_strlen(key))))
	{
		line = line + ft_strlen(key);
		while (*line == ' ')
			line++;
		return (line);
	}
	return (NULL);
}

int		get_int_len(int nb)
{
	unsigned int	index;

	index = 0;
	while (nb >= 10)
	{
		nb /= 10;
		index++;
	}
	return (index + 1);
}

void	ft_get_reso(char *line, t_all *all)
{
	char	*tmp;

	if (all->win.is_x != -1 || all->win.is_y != -1)
		quit(EXIT_FAILURE, TOO_MANY_RESO);
	if (!ft_is_reso_valid(line))
		quit(EXIT_FAILURE, CANT_GET_RESO);
	if (!(tmp = get_val(line, "R ")))
		quit(EXIT_FAILURE, CANT_GET_RESO);
	if (!(all->win.reso_x = ft_atoi(tmp)))
		quit(EXIT_FAILURE, CANT_GET_RESO);
	all->win.reso_x = (ft_atoi(tmp) < 180) ? 180 : all->win.reso_x;
	all->win.is_x = 1;
	tmp += get_int_len(all->win.reso_x);
	if (!(all->win.reso_y = ft_atoi(tmp)))
		quit(EXIT_FAILURE, CANT_GET_RESO);
	all->win.reso_y = (ft_atoi(tmp) < 180) ? 180 : all->win.reso_y;
	all->win.is_y = 1;
	tmp += get_int_len(all->win.reso_x);
	mlx_get_screen_size(all->win.mlx, &all->win.max_x, &all->win.max_y);
	if (all->win.reso_x > all->win.max_x)
		all->win.reso_x = all->win.max_x;
	if (all->win.reso_y > all->win.max_y)
		all->win.reso_y = all->win.max_y;
	all->all++;
}

char	*to_next_char(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			i = 1;
		if (ft_isdigit(*str) && i == 1)
		{
			if (j == 1)
				quit(EXIT_FAILURE, CANT_GET_COLOR);
			j = 1;
		}
		if (*str == c && *(str + 1))
			return (str + 1);
		str++;
		i++;
	}
	return (NULL);
}
