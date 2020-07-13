/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 14:05:14 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:58:42 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_tex_full(t_tex tex)
{
	if (!tex.no || !tex.so || !tex.sp || !tex.ea || !tex.we)
		return (0);
	return (1);
}

int		ft_is_reso_full(t_win win)
{
	if (win.is_x == 0 || win.is_y == 0)
		return (0);
	return (1);
}

void	ft_is_struct_full(t_all *all)
{
	if (!ft_is_tex_full(all->tex))
		quit(EXIT_FAILURE, TEX_MISSING);
	if (!ft_is_reso_full(all->win))
		quit(EXIT_FAILURE, RESO_MISSING);
	if (!all->f_color)
		quit(EXIT_FAILURE, F_COLOR_MISSING);
	if (!all->c_color)
		quit(EXIT_FAILURE, C_COLOR_MISSING);
}
