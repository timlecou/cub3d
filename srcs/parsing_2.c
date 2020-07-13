/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:44:05 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:54:16 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_empty(char *str)
{
	if (str[0] != '\0')
		return (0);
	return (1);
}

void	ft_manage_line(char *line, t_all *all)
{
	if (!ft_is_in_str(line[0], "NRSEWFC"))
		quit(EXIT_FAILURE, BAD_CHARACTER);
	if (line[0] == 'R')
		ft_get_reso(line, all);
	else if (line[0] == 'N' && line[1] == 'O')
		ft_get_north_texture(line, all);
	else if (line[0] == 'S' && line[1] == 'O')
		ft_get_south_texture(line, all);
	else if (line[0] == 'E' && line[1] == 'A')
		ft_get_east_texture(line, all);
	else if (line[0] == 'W' && line[1] == 'E')
		ft_get_west_texture(line, all);
	else if (line[0] == 'S')
		ft_get_sprite_texture(line, all);
	else if (line[0] == 'F')
		get_f_c_color(all, line, 'F');
	else if (line[0] == 'C')
		get_f_c_color(all, line, 'C');
	else if (!ft_is_empty(line))
	{
		ft_is_struct_full(all);
		quit(EXIT_FAILURE, "Unknown argument");
	}
}

void	ft_skip_empty_lines(t_all *all, char *line, int fd)
{
	int		ret;
	char	*tmp;

	ret = 1;
	tmp = NULL;
	while (ret == 1 && all->all < 8)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			quit(EXIT_FAILURE, ERROR_READ_FILE);
		tmp = line;
		line = ft_remove_all_spaces(line);
		free(tmp);
		ft_manage_line(line, all);
		free(line);
	}
}

int		ft_loop_map(t_all *all, char *line, int b, int c)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = NULL;
	tmp = NULL;
	if (ft_is_map_part(line))
	{
		b = 1;
		if (c == 1)
			quit(EXIT_FAILURE, ERROR_MAPS);
		tmp = all->map.tmp;
		all->map.tmp = ft_strjoin(all->map.tmp, line);
		free(tmp);
		tmp = NULL;
		tmp2 = all->map.tmp;
		all->map.tmp = ft_strjoin(all->map.tmp, ";");
		free(tmp2);
		tmp2 = NULL;
		all->map.width++;
		all->map.len = ((int)ft_strlen(line) >
		all->map.len) ? (int)ft_strlen(line) : all->map.len;
	}
	return (b);
}

void	ft_parse(t_all *all, int fd)
{
	char	*line;
	int		ret;
	int		b;
	int		c;

	ret = 1;
	b = 0;
	c = 0;
	line = NULL;
	ft_skip_empty_lines(all, line, fd);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		b = ft_loop_map(all, line, b, c);
		if (!ft_is_map_part(line) && b == 1)
			c = 1;
		free(line);
	}
	all->map.map = ft_split(all->map.tmp, ';');
	if (b == 0)
		quit(EXIT_FAILURE, MAP_MISSING);
	free(all->map.tmp);
}
