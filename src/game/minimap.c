/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:30:00 by aurodrig          #+#    #+#             */
/*   Updated: 2025/05/21 01:09:36 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	draw_square(t_game *game, int sx, int sy, int color)
{
	int	dy;
	int	dx;

	dy = 0;
	while (dy < MINIMAP_SCALE)
	{
		dx = 0;
		while (dx < MINIMAP_SCALE)
		{
			put_pixel(game, sx + dx, sy + dy, color);
			dx++;
		}
		dy++;
	}
}

static void	draw_player(t_game *game)
{
	int	px;
	int	py;
	int	dot_size;

	px = (int)(game->player_x * MINIMAP_SCALE);
	py = (int)(game->player_y * MINIMAP_SCALE);
	dot_size = MINIMAP_SCALE / 2;
	draw_square(game, px - dot_size / 2, py - dot_size / 2, 0xFF0000);
}

static void	draw_direction_line(t_game *game)
{
	int		px;
	int		py;
	int		i;
	float	x_f;
	float	y_f;

	px = (int)(game->player_x * MINIMAP_SCALE);
	py = (int)(game->player_y * MINIMAP_SCALE);
	x_f = px;
	y_f = py;
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		put_pixel(game, (int)x_f, (int)y_f, 0xFF0000);
		x_f += game->dir_x;
		y_f += game->dir_y;
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	row;
	int	col;
	int	sx;
	int	sy;
	int	color;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			sx = col * MINIMAP_SCALE;
			sy = row * MINIMAP_SCALE;
			if (game->map[row][col] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			draw_square(game, sx, sy, color);
			col++;
		}
		row++;
	}
	draw_player(game);
	draw_direction_line(game);
}
