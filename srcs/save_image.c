/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 14:14:45 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 17:55:18 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	int_to_uchar(unsigned char *header, int size)
{
	header[0] = (unsigned char)(size);
	header[1] = (unsigned char)(size >> 8);
	header[2] = (unsigned char)(size >> 16);
	header[3] = (unsigned char)(size >> 24);
}

int		ft_write_bmp_header(int fd, t_all *all)
{
	int				size;
	int				i;
	unsigned char	header[54];

	size = 54 + (all->win.reso_x * all->win.reso_y);
	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)(0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	int_to_uchar(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	int_to_uchar(header + 18, all->win.reso_x);
	int_to_uchar(header + 22, all->win.reso_y);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	return (!(write(fd, header, sizeof(char) * 54) < 0));
}

int		ft_write_bmp_pixel_array(int fd, t_all *all)
{
	int	x;
	int	y;
	int	color;

	color = 0;
	y = all->win.reso_y;
	while (y > 0)
	{
		x = 0;
		while (x < all->win.reso_x)
		{
			color = get_pixel(all, x, y);
			if (write(fd, &color, 3) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int		ft_save_bmp(int fd, t_all *all)
{
	if (!ft_write_bmp_header(fd, all))
		quit(EXIT_FAILURE, CANT_WRITE_HEADER);
	if (!ft_write_bmp_pixel_array(fd, all))
		quit(EXIT_FAILURE, CANT_WRITE_BMP_ARRAY);
	return (1);
}

void	ft_save_image(t_all *all)
{
	int	fd;

	if (all->save == 1)
	{
		all->save = 0;
		if ((fd = open("screenshot.bmp", O_RDWR |
		O_CREAT, S_IRUSR | S_IWUSR)) < 0)
			quit(EXIT_FAILURE, CANT_OPEN_BMP);
		ft_printf_fd(1, "Saving image...\n");
		if (!ft_save_bmp(fd, all))
			quit(EXIT_FAILURE, CANT_SAVE_BMP);
		close(fd);
		quit(EXIT_SUCCESS, "=> Image saved in screenshot.bmp");
	}
}
