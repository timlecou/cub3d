/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:18:20 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:54:37 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_deal_check_map(int n)
{
	if (n == 0)
		quit(EXIT_FAILURE, "Bad character");
	if (n == 1)
		quit(EXIT_FAILURE, "Unclosed map");
	if (n == 2)
		quit(EXIT_FAILURE, "Bad pos");
}

int		ft_check_unclosed(char **map, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[i - 1 + x] && x < 3)
	{
		y = 0;
		if (!map[i - 1 + x][j - 1])
			return (0);
		if (!map[i - 1 + x][j])
			return (0);
		if (!map[i - 1 + x][j + 1])
			return (0);
		while (map[i - 1 + x][j - 1 + y] && y < 3)
		{
			if (map[i - 1 + x][j - 1 + y] == ' ' && x - 1 != i && y - 1 != j)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int		ft_is_color_valid(char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == ',')
			j++;
		if (str[i] != ' ' && str[i] != ',' && !ft_isdigit(str[i]))
			return (0);
		if (ft_isdigit(str[i]))
		{
			k++;
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	return (!(j != 2 || k != 3));
}

char	*ft_remove_all_spaces(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	return (ft_strdup(&str[i]));
}

int		ft_is_in_str(char c, char *str)
{
	int	i;

	i = 0;
	if (!c)
		return (1);
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
