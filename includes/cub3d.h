/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timlecou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 11:34:40 by timlecou          #+#    #+#             */
/*   Updated: 2020/06/26 21:40:16 by timlecou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "mlx.h"
# include "structure.h"
# include "define.h"
# include <fcntl.h>
# include <math.h>

void		ft_get_reso(char *line, t_all *all);
void		ft_get_south_texture(char *line, t_all *all);
void		ft_get_north_texture(char *line, t_all *all);
void		ft_get_east_texture(char *line, t_all *all);
void		ft_get_west_texture(char *line, t_all *all);
void		ft_get_sprite_texture(char *line, t_all *all);
void		ft_get_floor_color(char *line, t_all *all);
void		ft_get_ceiling_color(char *line, t_all *all);
void		ft_free_t_all(t_all *all);
int			ft_check_map(t_all *all);
void		ft_deal_check_map(int n);
int			get_next_line(int fd, char **line);
char		*ft_cut_begin(char *str);
char		*ft_cut(char *str);
int			ft_is_pos_char(char c);
void		ft_deal_check_map(int n);
void		ft_get_ceiling_color(char *line, t_all *all);
void		ft_get_floor_color(char *line, t_all *all);
int			ft_check_unclosed(char **map, int i, int j);
void		ft_get_south_texture(char *line, t_all *all);
void		ft_get_north_texture(char *line, t_all *all);
void		ft_get_east_texture(char *line, t_all *all);
void		ft_get_west_texture(char *line, t_all *all);
void		ft_get_sprite_texture(char *line, t_all *all);
void		ft_init_win(t_all *all);
void		ft_init_tex(t_all *all);
void		ft_init_img(t_all *all);
void		ft_init_floor(t_all *all);
void		ft_init_ceiling(t_all *all);
void		ft_init_map(t_all *all);
void		ft_init_player(t_all *all);
void		ft_init_t_all(t_all *all);
int			ft_is_map_part(char *str);
void		ft_print_map(char **map);
int			ft_x_p(t_all *all);
int			ft_y_p(t_all *all);
void		ft_init_pos(t_all *all);
void		ft_init_vector(t_all *all);
char		*ft_add_line(char *line);
void		ft_print_player(t_all *all);
int			ft_is_wall(int x, int y, t_all *all, int i);
int			ft_is_sprite(int x, int y, t_all *all);
void		ft_mlx(t_all *all);
int			ft_hit_key(int key, t_all *all);
int			ft_release_key(int key, t_all *all);
int			ft_core(t_all *all);
void		ft_window(t_all *all);
void		ft_ray(t_all *all, float op, int j);
void		ft_print_ray(t_all *all);
void		ft_print_ray_minimap(t_all *all);
void		ft_parse(t_all *all, int fd);
void		ft_manage_line(char *line, t_all *all);
int			ft_is_near_wall(int x, int y, t_all *all);
void		ft_print_column(int index, t_all *all);
int			ft_wall_direction(t_all *all);
int			ft_sprite_direction(int x, int y, t_all *all);
void		ft_put_image_pixel(t_all *all, int x, int y, int color);
void		ft_turn_right(t_all *all);
void		ft_turn_left(t_all *all);
void		ft_go_up(t_all *all);
void		ft_go_back(t_all *all);
void		ft_go_right(t_all *all);
void		ft_go_left(t_all *all);
int			ft_near_down(t_all *all);
int			ft_near_up(t_all *all);
int			ft_near_right(t_all *all);
int			ft_near_left(t_all *all);
void		ft_display_minimap(t_all *all);
void		ft_north_tex(t_all *all, int i, int size);
void		ft_south_tex(t_all *all, int i, int size);
void		ft_east_tex(t_all *all, int i, int size);
void		ft_west_tex(t_all *all, int i, int size);
void		ft_sprite_tex(t_all *all, int l, int j, int index);
void		ft_print_sprite_column(t_all *all, int j);
void		ft_print_sprites(t_all *all);
void		ft_parse_sprite(t_all *all);
void		ft_init_t_sprite(t_sprite *elem, t_all *all);
void		ft_init_sprite_tab(t_all *all);
void		ft_sort_sprite_tab(t_all *all);
void		ft_sprite_casting(t_all *all);
void		ft_save_image(t_all *all);
int			get_color_from_rgb(int r, int g, int b);
void		get_f_c_color(t_all *all, char *line, char c);
void		ft_is_struct_full(t_all *all);
int			ft_check_check_map(t_all *all, int i, int j);
void		ft_set_player_pos(t_all *all);
void		ft_init_sprite_b(t_all *all);
void		ft_print_minimap_color(t_all *all, int i, int j);
int			get_pixel(t_all *all, int x, int y);
void		ft_set_color(t_all *all, char c, int *colors);
char		*ft_remove_spaces_end(char *str);
int			ft_is_color_valid(char *line);
char		*to_next_char(char *tmp, char c);
void		quit(int flag, char *str);
int			ft_get_gun_tex(t_all *all, int i, int j);
void		ft_print_pistol(t_all *all);
char		*ft_remove_all_spaces(char *str);
int			ft_is_in_str(char c, char *str);
int			ft_is_in_map(t_all *all, int x, int y);
int			ft_player_in_sprite(t_all *all, int i);
void		ft_check_color_2(char *str);
void		mlx_del(void *mlx_ptr);
#endif
