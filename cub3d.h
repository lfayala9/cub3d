/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:32 by layala-s          #+#    #+#             */
/*   Updated: 2025/05/06 10:38:12 by layala-s         ###   ########.fr       */
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

/*FUNCTIONS*/

void	free_game(t_game *g);
void	raycast(t_game *game);
void	init_mlx(t_game *game);
void	handle_input(t_game *game);
void	get_elements(t_game *g, char *file);
void	copy_str(char *dest, char*src, int n);
void	exit_error(char *msg, int code_free, t_game *g);
void	init_elements(char **str, char *element, int n, t_game *g);
void	start_game(t_game *game);
void	get_map(t_game *g, char **copy);
void	draw_vertical_line(t_game *game, int x, int y0, int y1);
int		draw_frame(t_game *game);
int		check_input(int ac, char **av);
int		handle_key_press(int keycode, t_game *game);
int		check_values(char **map, t_game *g);
int		check_player_and_limits(char **map, int x, int y, t_game *g);
int		check_edges(char **map);
int		check_first_last(char **map);
void	validate_map(t_game *g);
int		parse_data(t_game *g, char *file);
int		handle_key_release(int keycode, t_game *game);
void	get_position(t_game *g);
int		check_extension(char *filename, char *extension);
double	ft_abs(double x);
t_game	*init_struct(t_game *game);

#endif
