/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:15:26 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:35:37 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARR 65361
# define RIGHT_ARR 65363
# define TAB 65289
# define KEY_PRESS 2
# define DESTROY_BUTTON 17
# define FOV 0.66
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define ROTATION_SPEED 0.05
# define SPEED_MOVEMENT 0.15
# define WALL_CHANGE 0.1

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_cam
{
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	double	delta_d_x;
	double	delta_d_y;
	double	side_d_x;
	double	side_d_y;
	double	vert_wall_d;
	int		step_x;
	int		step_y;
	int		mapcoord_x;
	int		mapcoord_y;
	int		side;
}	t_cam;

typedef struct s_ray
{
	int		height;
	int		start;
	int		end;
	double	wall;
	int		texture_x;
	int		texture_y;
	double	texture_pos;
	double	jump;
}	t_ray;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_info;

typedef struct s_img
{
	char	*path_textures;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_map
{
	char	**matrix;
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_map;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		recalculate;
	int		key_detected;
	t_map	map;
	t_info	player;
	t_img	background;
}	t_cube;

void	ft_init_cube(t_cube *cube);
void	ft_start_game(t_cube *cube);
void	ft_draw(t_img *background, int start_y, int until_y, int color);
void	ft_raycasting(t_cube *cube);
void	ft_draw_wall(t_cube *cube, t_cam *cam, int column_counter);
void	ft_print_data(t_cube *cube);
void	ft_get_player_pos(char **map, t_info *player);
void	ft_move_plr_forward(t_cube *cube);
void	ft_move_plr_backward(t_cube *cube);
void	ft_move_plr_right(t_cube *cube);
void	ft_move_plr_left(t_cube *cube);
void	ft_move_pov_left(t_cube *cube);
void	ft_move_pov_right(t_cube *cube);
void	ft_pixel_background(t_img *background, int x, int y, int color);
void	ft_print_game(t_cube *cube);
void	ft_minimap_handler(t_cube *cube);
void	ft_arrow_handler(int keycode, t_cube *cube);
void	ft_wasd_handler(int keycode, t_cube *cube);
void	ft_game_calculate(t_cube *cube);

int		ft_pixel_texture(t_img *texture, int x, int y);
int		ft_map(t_map *map, int fd);
int		ft_ac_error(int ac);
int		ft_info_game(t_cube *cube, char *path);
int		ft_check_valid_map(char **map);
int		ft_open_map(char *path, char *ext);
int		ft_check_extension(char *path, char *ext);
int		ft_key_handler(int keycode, t_cube *cube);
int		ft_quit_game(t_cube *cube);
int		ft_check_textures(t_cube *cube, int fd);
int		ft_check_after_map(int fd);
int		ft_take_max_len(char **mat);
int		ft_check_texture_validity(char *path_text, char *line_mover, int i);
int		ft_check_color_validity(int *color, char *line_mover, int i);
int		ft_invalid_texture(void);
int		ft_invalid_game(t_cube *cube);

bool	ft_isarrow(int keycode);
bool	ft_iswasd(int keycode);

#endif
