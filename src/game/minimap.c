/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:30:00 by aurodrig          #+#    #+#             */
/*   Updated: 2025/05/19 22:48:47 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"   // tamaño en pixels por celda del minimapa

// Dibuja un cuadrado de color 'color' de tamaño MINIMAP_SCALE
static void draw_square(t_game *game, int sx, int sy, int color)
{
    int dy = 0;
    while (dy < MINIMAP_SCALE)
    {
        int dx = 0;
        while (dx < MINIMAP_SCALE)
        {
            mlx_pixel_put(game->mlx_ptr, game->mlx_win,
                          sx + dx, sy + dy, color);
            dx++;
        }
        dy++;
    }
}

static void draw_player(t_game *game)
{
    int px = (int)(game->player_x * MINIMAP_SCALE);
    int py = (int)(game->player_y * MINIMAP_SCALE);
    int dot_size = MINIMAP_SCALE / 2;
    draw_square(game, px - dot_size / 2, py - dot_size / 2, 0xFF0000);
}

static void draw_direction_line(t_game *game)
{
    int px = (int)(game->player_x * MINIMAP_SCALE);
    int py = (int)(game->player_y * MINIMAP_SCALE);
    int lx = px + (int)(game->dir_x * MINIMAP_SCALE);
    int ly = py + (int)(game->dir_y * MINIMAP_SCALE);
    int dx = lx - px;
    int dy = ly - py;
    int steps = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
    float ix = dx / (float)steps;
    float iy = dy / (float)steps;
    float x_f = px;
    float y_f = py;
    int i = 0;

    while (i < steps)
    {
        mlx_pixel_put(game->mlx_ptr, game->mlx_win,
                      (int)x_f, (int)y_f, 0xFF0000);
        x_f += ix;
        y_f += iy;
        i++;
    }
}

void draw_minimap(t_game *game)
{

    int row = 0;
    while (game->map[row])
    {
        int col = 0;
        while (game->map[row][col])
        {
            int sx = col * MINIMAP_SCALE;
            int sy = row * MINIMAP_SCALE;
            int color = (game->map[row][col] == '1')
                        ? 0xFFFFFF : 0x000000;
            draw_square(game, sx, sy, color);
            col++;
        }
        row++;
    }
    draw_player(game);
    draw_direction_line(game);
}