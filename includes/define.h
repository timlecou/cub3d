/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 17:17:09 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 16:17:36 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# define K_RIGHT 124
# define K_LEFT 123
# define K_GO_RIGHT 2
# define K_GO_LEFT 0
# define K_UP 13
# define K_DOWN 1
# define K_ESC 53
# define ERROR_MLX_INIT "Mlx initialisation failed"
# define ERROR_WIN "Fail opening window"
# define ERROR_NB_ARG "Too few arguments"
# define ERROR_READ_FILE "The reading of the file failed"
# define CANT_ALLOCATE "Can't allocate memory"
# define ERROR_OPEN_FILE "Can't open the file *.cub"
# define CANT_CREATE_IMAGE "Can't create image"
# define CANT_OPEN_BMP "screenshot.bmp : Can't open file"
# define CANT_INITIALISE_IMAGE "Can't initialise image"
# define CANT_LOAD_TEX "Can't load XPM file"
# define CANT_GET_TEX_DATA "Can't get texture data"
# define CANT_GET_COLOR "Can't get color"
# define CANT_SAVE_BMP "Couldn't save image"
# define CANT_WRITE_HEADER "Couldn't write header in .bmp file"
# define CANT_WRITE_BMP_ARRAY "Couldn't write pixel array in .bmp file"
# define CLOSE_GAME "game closed"
# define TOO_LONG_COLOR "color must be between 0 and 255"
# define BAD_CHARACTER "Bad character in .cub file"
# define CANT_GET_RESO "Can't get resolution values"
# define TEX_MISSING "a texture file is missing"
# define RESO_MISSING "resolution value is missing"
# define F_COLOR_MISSING "floor color is missing"
# define C_COLOR_MISSING "ceiling color is missing"
# define TOO_MANY_SO_TEX "too many south texture paths in file"
# define TOO_MANY_NO_TEX "too many north texture paths in file"
# define TOO_MANY_SP_TEX "too many sprite texture paths in file"
# define TOO_MANY_EA_TEX "too many east texture paths in file"
# define TOO_MANY_WE_TEX "too many west texture paths in file"
# define TOO_MANY_RESO "too many resolution values in file"
# define TOO_MANY_F_COLOR "too many floor color values in file"
# define TOO_MANY_C_COLOR "too many ceiling color values in file"
# define ERROR_MAPS "problem to load the map from file"
# define MAP_MISSING "map is missing"
# define NOT_A_CUB_FILE "not a .cub file"
# define SPEED 2.0
# define SENSI 8
# define COLOR_PLAYER 0xE24141
# define COLOR_RAY 0xFC0909
# define COLOR_WALL 0x010000
# define COLOR_SPRITE 0x11E3E3
# define COLOR_FLOOR 0xFFFFFF0
# define COLOR_SPAWN 0x11E331

#endif
