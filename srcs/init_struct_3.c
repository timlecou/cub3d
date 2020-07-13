/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 14:03:38 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:52:32 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_t_sprite(t_sprite *elem, t_all *all)
{
	elem->x = 0;
	elem->y = 0;
	elem->hit_x = 0;
	elem->hit_y = 0;
	elem->ray = 0;
	elem->is_ray = 0;
	elem->max_ray = 1;
	elem->last_ray = 0;
	elem->b = 0;
	elem->dist = 0;
	elem->start = 0;
	elem->count = 0;
	elem->max_count = 0;
	elem->init = 0;
	if (!(elem->tex.ptr = mlx_xpm_file_to_image(all->win.mlx,
	all->tex.sp, &elem->tex.width, &elem->tex.height)))
		quit(EXIT_FAILURE, CANT_LOAD_TEX);
	if (!(elem->tex.data = (int*)mlx_get_data_addr(elem->tex.ptr,
	&elem->tex.bpp, &elem->tex.sl, &elem->tex.endian)))
		quit(EXIT_FAILURE, CANT_GET_TEX_DATA);
	mlx_destroy_image(all->win.mlx, elem->tex.ptr);
}

void	ft_init_sprite_tab(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->sprite_nb)
	{
		ft_init_t_sprite(&all->sprites[i], all);
		i++;
	}
}

void	ft_init_vector(t_all *all)
{
	all->vector.x = 0;
	all->vector.y = 0;
}
