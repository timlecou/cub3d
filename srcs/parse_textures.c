/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 10:18:54 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:53:53 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_remove_spaces_end(char *str)
{
	int		i;
	char	*res;

	i = (int)ft_strlen(str);
	i--;
	while (str[i] != '\0' && str[i] == ' ')
		i--;
	i++;
	if (!(res = (char*)malloc(sizeof(char) * (i + 2))))
		quit(EXIT_FAILURE, CANT_ALLOCATE);
	if (!ft_strlcpy(res, str, i + 1))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	free(str);
	return (res);
}

void	ft_get_south_texture(char *line, t_all *all)
{
	int		i;

	i = 0;
	if (all->tex.so != NULL)
		quit(EXIT_FAILURE, TOO_MANY_SO_TEX);
	while (line[i] != '.' && line[i] != '\0')
	{
		if (line[i] != ' ' && i > 1)
			quit(EXIT_FAILURE, "Bad south texture path");
		i++;
	}
	all->tex.so = ft_remove_spaces_end(ft_strdup(&line[i]));
	all->all++;
}

void	ft_get_east_texture(char *line, t_all *all)
{
	int		i;

	i = 0;
	if (all->tex.ea != NULL)
		quit(EXIT_FAILURE, TOO_MANY_EA_TEX);
	while (line[i] != '.' && line[i] != '\0')
	{
		if (line[i] != ' ' && i > 1)
			quit(EXIT_FAILURE, "Bad east texture path");
		i++;
	}
	all->tex.ea = ft_remove_spaces_end(ft_strdup(&line[i]));
	all->all++;
}

void	ft_get_west_texture(char *line, t_all *all)
{
	int		i;

	i = 0;
	if (all->tex.we != NULL)
		quit(EXIT_FAILURE, TOO_MANY_WE_TEX);
	while (line[i] != '.' && line[i] != '\0')
	{
		if (line[i] != ' ' && i > 1)
			quit(EXIT_FAILURE, "Bad west texture path");
		i++;
	}
	all->tex.we = ft_remove_spaces_end(ft_strdup(&line[i]));
	all->all++;
}

void	ft_get_north_texture(char *line, t_all *all)
{
	int		i;

	i = 0;
	if (all->tex.no != NULL)
		quit(EXIT_FAILURE, TOO_MANY_NO_TEX);
	while (line[i] != '.' && line[i] != '\0')
	{
		if (line[i] != ' ' && i > 1)
			quit(EXIT_FAILURE, "Bad north texture path");
		i++;
	}
	all->tex.no = ft_remove_spaces_end(ft_strdup(&line[i]));
	all->all++;
}
