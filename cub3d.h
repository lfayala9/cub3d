/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:32 by layala-s          #+#    #+#             */
/*   Updated: 2025/05/12 17:20:46 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*INCLUDES*/

# include <math.h> 
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"

# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define MAX_KEYS 70000
# define WIN_WIDTH 720
# define WIN_HEIGHT 480

/*STRUCTS*/

typedef struct s_element
{
	char	*no_tx;
	char	*so_tx;
	char	*ea_tx;
	char	*we_tx;
	char	*c_rgb;
	char	*f_rgb;
}	t_element;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			keys[MAX_KEYS];
	int			win_height;
	int			color;
	int			p_count;
	int			win_width;
	char		**map;
	char		**elements;
	double		player_x;
	double		player_y;
	double		plane_x;
	double		plane_y;
	double		dir_x;
	double		dir_y;
	t_element	*e;
}	t_game;

typedef struct s_ray_data
{
	double	camera_x;
	double	ray_x;
	double	ray_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	double	perp_dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray_data;

/*FUNCTIONS*/

void	free_game(t_game *g);
void	raycast(t_game *game);
void	init_mlx(t_game *game);
void	validate_map(t_game *g);
void	get_position(t_game *g);
void	start_game(t_game *game);
void	handle_input(t_game *game);
void	set_plane(t_game *g, char ori);
void	get_map(t_game *g, char **copy);
void	set_direction(t_game *g, char ori);
void	get_elements(t_game *g, char **copy);
void	copy_str(char *dest, char*src, int n);
void	init_ray(t_game *game, t_ray_data *r, int x);
void	draw_slice(t_game *game, t_ray_data *r, int x);
void	exit_error(char *msg, int code_free, t_game *g);
void	draw_vertical_line(t_game *game, int x, int y0, int y1);
void	init_elements(char **str, char *element, int n, t_game *g);
int		check_edges(char **map);
int		exit_game(t_game *game);
int		draw_frame(t_game *game);
char	**get_rgb(char *color, t_game *g);
int 	parse_rgb(char **rgb);
int		check_first_last(char **map);
int		check_first_last(char **map);
int		check_input(int ac, char **av);
int		parse_data(t_game *g, char **copy);
int	check_rgb(char **rgb, t_game *g);
void	free_rgb(char **rgb);
int		check_values(char **map, t_game *g);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
int		check_extension(char *filename, char *extension);
int		check_player_and_limits(char **map, int x, int y, t_game *g);
double	ft_abs(double x);
t_game	*init_struct(t_game *game);

#endif
