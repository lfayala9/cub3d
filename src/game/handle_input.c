/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:54:33 by aurodrig          #+#    #+#             */
/*   Updated: 2025/05/06 10:42:35 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	move(t_game *g, double dx, double dy)
{
	double new_x = g->player_x + dx;
	double new_y = g->player_y + dy;

	if (g->map[(int)new_y][(int)g->player_x] != '1')
		g->player_y = new_y;
	if (g->map[(int)g->player_y][(int)new_x] != '1')
		g->player_x = new_x;
}

static void	rotate(t_game *g, double angle)
{
	double old_dir_x = g->dir_x;
	double old_plane_x = g->plane_x;

	g->dir_x = g->dir_x * cos(angle) - g->dir_y * sin(angle);
	g->dir_y = old_dir_x * sin(angle) + g->dir_y * cos(angle);

	g->plane_x = g->plane_x * cos(angle) - g->plane_y * sin(angle);
	g->plane_y = old_plane_x * sin(angle) + g->plane_y * cos(angle);
}

void	handle_input(t_game *g)
{
	double move_speed = 0.05;
	double rot_speed = 0.05;

	if (g->keys[XK_w])
		move(g, g->dir_x * move_speed, g->dir_y * move_speed);
	if (g->keys[XK_s])
		move(g, -g->dir_x * move_speed, -g->dir_y * move_speed);
	if (g->keys[XK_a])
		move(g, -g->plane_x * move_speed, -g->plane_y * move_speed);
	if (g->keys[XK_d])
		move(g, g->plane_x * move_speed, g->plane_y * move_speed);
	if (g->keys[XK_Left])
		rotate(g, -rot_speed);
	if (g->keys[XK_Right])
		rotate(g, rot_speed);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
		game->keys[keycode] = 1;
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		free_game(game);
		exit(0);
	}
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
		game->keys[keycode] = 0;
	return (0);
}
