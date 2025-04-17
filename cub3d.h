/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:32 by layala-s          #+#    #+#             */
/*   Updated: 2025/04/17 18:23:03 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*INCLUDES*/

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/keysym.h> // 🔑 Esto es importante para usar XK_w, XK_s, etc
#include <math.h> 

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
#define MAX_KEYS 70000
// Puedes definirlo tú mismo si no lo está haciendo X11/keysym.h
#define KEY_LEFT 65361
#define KEY_RIGHT 65363


/*STRUCTS*/

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	char	**map;

	double	player_x;
	double	player_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;

	int		keys[MAX_KEYS]; // 🔑 Estado de teclas presionadas
}	t_game;

/*FUNCTIONS*/

//void	init_mlx(t_game *game);
int		draw_frame(t_game *game);
void	raycast(t_game *game);
void	draw_vertical_line(t_game *game, int x, int y0, int y1, int color);
double	ft_abs(double x);
int		handle_key_press(int keycode, t_game *game);
int		handle_key_release(int keycode, t_game *game);
void	handle_input(t_game *game);

#endif
