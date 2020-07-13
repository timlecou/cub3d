/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 19:07:46 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:58:36 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_arg_cub(t_all *all, char **av)
{
	if (ft_strcmp(av[2], "--save") == 0)
		all->save = 1;
}

int		main(int ac, char **av)
{
	t_all	all;
	int		fd;

	if (ac < 2)
		quit(EXIT_FAILURE, ERROR_NB_ARG);
	ft_init_t_all(&all);
	if (ac == 3)
		ft_arg_cub(&all, av);
	if (ft_strcmp(&av[1][(int)ft_strlen(av[1]) - 4], ".cub") != 0)
		quit(EXIT_FAILURE, NOT_A_CUB_FILE);
	if ((fd = open(av[1], O_RDWR)) == -1)
		quit(EXIT_FAILURE, ERROR_OPEN_FILE);
	ft_parse(&all, fd);
	if (!(all.win.mlx = mlx_init()))
		quit(EXIT_FAILURE, ERROR_MLX_INIT);
	if (!(all.win.win = mlx_new_window(all.win.mlx,
	all.win.reso_x, all.win.reso_y, "Cub3D")))
		quit(EXIT_FAILURE, ERROR_WIN);
	ft_deal_check_map(ft_check_map(&all));
	all.map.wall_len = (all.win.reso_x / 5) / 10;
	ft_init_pos(&all);
	ft_mlx(&all);
	mlx_loop(all.win.mlx);
	ft_free_t_all(&all);
	return (0);
}
