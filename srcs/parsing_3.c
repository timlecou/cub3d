/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 17:59:57 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:54:26 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_color_from_rgb(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

void	ft_set_color(t_all *all, char c, int *colors)
{
	if (c == 'F')
	{
		if (all->f_color != 0)
			quit(EXIT_FAILURE, TOO_MANY_F_COLOR);
		all->f_color = get_color_from_rgb(colors[0], colors[1], colors[2]);
	}
	else if (c == 'C')
	{
		if (all->c_color != 0)
			quit(EXIT_FAILURE, TOO_MANY_C_COLOR);
		all->c_color = get_color_from_rgb(colors[0], colors[1], colors[2]);
	}
}

void	ft_parse_sprite(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map.map[i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (all->map.map[i][j] == '2')
				all->sprite_nb++;
			j++;
		}
		i++;
	}
	if (!(all->sprites = (t_sprite*)malloc(sizeof(t_sprite)
	* all->sprite_nb)))
		quit(EXIT_FAILURE, "Can't allocate sprite array");
}

void	ft_get_sprite_texture(char *line, t_all *all)
{
	int		i;

	i = 0;
	if (all->tex.sp != NULL)
		quit(EXIT_FAILURE, TOO_MANY_SP_TEX);
	while (line[i] != '.' && line[i] != '\0')
	{
		if (line[i] != ' ' && i > 0)
			quit(EXIT_FAILURE, "Bad sprite texture path");
		i++;
	}
	all->tex.sp = ft_remove_spaces_end(ft_strdup(&line[i]));
	all->all++;
}

void	get_f_c_color(t_all *all, char *line, char c)
{
	int		colors[3];
	int		index;
	char	*tmp;

	index = 0;
	tmp = line + 2;
	if (!tmp)
		quit(EXIT_FAILURE, "can't get color");
	if (!ft_is_color_valid(tmp))
		quit(EXIT_FAILURE, BAD_CHARACTER);
	while (index < 3)
	{
		ft_check_color_2(tmp);
		colors[index++] = ft_atoi(tmp);
		if (!(tmp = to_next_char(tmp, ',')))
			break ;
	}
	if (index < 3)
		quit(EXIT_FAILURE, "can't get color");
	if (colors[0] > 255 || colors[1] > 255 || colors[2] > 255)
		quit(EXIT_FAILURE, TOO_LONG_COLOR);
	ft_set_color(all, c, colors);
	all->all++;
}
