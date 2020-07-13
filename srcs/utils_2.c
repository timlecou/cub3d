/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 18:37:30 by timlecou          #+#    #+#             */
/*   Updated: 2020/07/12 20:18:22 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	upload_xpm2(t_all *all)
{
	if (!(all->tex.i_no.ptr = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.no, &all->tex.i_no.width, &all->tex.i_no.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(all->tex.i_no.data = (int*)mlx_get_data_addr(all->tex.i_no.ptr,
	&all->tex.i_no.bpp, &all->tex.i_no.sl, &all->tex.i_no.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, all->tex.i_no.ptr);
	if (!(all->tex.i_sp.ptr = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.sp, &all->tex.i_sp.width, &all->tex.i_sp.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(all->tex.i_sp.data = (int*)mlx_get_data_addr(all->tex.i_sp.ptr,
	&all->tex.i_sp.bpp, &all->tex.i_sp.sl, &all->tex.i_sp.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, all->tex.i_sp.ptr);
	if (!(all->player.gun.ptr = mlx_xpm_file_to_image(all->win.mlx,
	"textures/pistol.xpm", &all->player.gun.width, &all->player.gun.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(all->player.gun.data = (int*)mlx_get_data_addr(all->player.gun.ptr,
	&all->player.gun.bpp, &all->player.gun.sl, &all->player.gun.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, all->player.gun.ptr);
}

void	upload_xpm(t_all *all)
{
	if (!(all->tex.i_we.ptr = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.we, &all->tex.i_we.width, &all->tex.i_we.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(all->tex.i_we.data = (int*)mlx_get_data_addr(all->tex.i_we.ptr,
	&all->tex.i_we.bpp, &all->tex.i_we.sl, &all->tex.i_we.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, all->tex.i_we.ptr);
	if (!(all->tex.i_so.ptr = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.so, &all->tex.i_so.width, &all->tex.i_so.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(all->tex.i_so.data = (int*)mlx_get_data_addr(all->tex.i_so.ptr,
	&all->tex.i_so.bpp, &all->tex.i_so.sl, &all->tex.i_so.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, all->tex.i_so.ptr);
	if (!(all->tex.i_ea.ptr = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.ea, &all->tex.i_ea.width, &all->tex.i_ea.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(all->tex.i_ea.data = (int*)mlx_get_data_addr(all->tex.i_ea.ptr,
	&all->tex.i_ea.bpp, &all->tex.i_ea.sl, &all->tex.i_ea.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, all->tex.i_ea.ptr);
	upload_xpm2(all);
}

int		close_red_button(void)
{
	quit(EXIT_SUCCESS, CLOSE_GAME);
	return (0);
}

void	ft_mlx(t_all *all)
{
	if ((all->img.ptr = mlx_new_image(all->win.mlx,
	all->win.reso_x, all->win.reso_y)) == NULL)
		quit(EXIT_FAILURE, CANT_CREATE_IMAGE);
	if ((all->img.data = (int*)mlx_get_data_addr(all->img.ptr,
	&all->img.bpp, &all->img.sl, &all->img.endian)) == NULL)
		quit(EXIT_FAILURE, CANT_INITIALISE_IMAGE);
	upload_xpm(all);
	ft_parse_sprite(all);
	ft_print_ray(all);
	ft_save_image(all);
	mlx_put_image_to_window(all->win.mlx, all->win.win, all->img.ptr, 0, 0);
	mlx_hook(all->win.win, 2, 1L << 0, ft_hit_key, (void*)all);
	mlx_hook(all->win.win, 3, 2L, ft_release_key, (void*)all);
	mlx_hook(all->win.win, 17, 1L << 0, close_red_button, (void *)all);
	mlx_loop_hook(all->win.mlx, ft_core, all);
}

int		ft_is_wall(int x, int y, t_all *all, int i)
{
	int	k;
	int	l;

	l = (x % 64 > 0) ? (x / 64) + 1 : (x / 64);
	k = (y % 64 > 0) ? (y / 64) + 1 : (y / 64);
	if (all->map.map[k][l] == '1')
		return (0);
	if (i == 0)
		if (all->map.map[k][l] == '2')
			return (0);
	return (1);
}
