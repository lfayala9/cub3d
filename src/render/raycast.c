/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:35:24 by aurodrig          #+#    #+#             */
/*   Updated: 2025/05/12 17:33:59 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../../cub3d.h"

//Raycaster completo con techo, pared y suelo
void	raycast(t_game *game)
{
	//printf("👉 raycast ejecutándose\n");  // 👈 DEBUG
	int		x;
	t_ray_data r;

	x = 0;
	while (x < game->win_width)
	{
		// 1️⃣ Dirección del rayo
		r.camera_x = 2.0 * x / game->win_width - 1.0;
		r.ray_x = game->dir_x + game->plane_x * r.camera_x;
		r.ray_y = game->dir_y + game->plane_y * r.camera_x;

		r.map_x = (int)(game->player_x);
		r.map_y = (int)(game->player_y);

		if (r.ray_x == 0)
			r.delta_x = 1e30;
		else
			r.delta_x = ft_abs(1.0 / r.ray_x);
		if (r.ray_y == 0)
			r.delta_y = 1e30;
		else
			r.delta_y = ft_abs(1.0 / r.ray_y);

		// 2️⃣ Steps y side distances
		if (r.ray_x < 0)
		{
			r.step_x = -1;
			r.side_x = (game->player_x - r.map_x) * r.delta_x;
		}
		else
		{
			r.step_x = 1;
			r.side_x = (r.map_x + 1.0 - game->player_x) * r.delta_x;
		}
		if (r.ray_y < 0)
		{
			r.step_y = -1;
			r.side_y = (game->player_y - r.map_y) * r.delta_y;
		}
		else
		{
			r.step_y = 1;
			r.side_y = (r.map_y + 1.0 - game->player_y) * r.delta_y;
		}

		// 3️⃣ DDA
		r.hit = 0;
		while (r.hit == 0)
		{
			if (r.side_x < r.side_y)
			{
				r.side_x += r.delta_x;
				r.map_x += r.step_x;
				r.side = 0;
			}
			else
			{
				r.side_y += r.delta_y;
				r.map_y += r.step_y;
				r.side = 1;
			}
			if (game->map[r.map_y][r.map_x] == '1')
				r.hit = 1;
		}

		// 4️⃣ Distancia perpendicular al muro
		if (r.side == 0)
			r.perp_dist = (r.map_x - game->player_x + (1 - r.step_x) / 2.0) / r.ray_x;
		else
			r.perp_dist = (r.map_y - game->player_y + (1 - r.step_y) / 2.0) / r.ray_y;

		// 5️⃣ Tamaño y posición de la pared
		r.line_height = (int)(game->win_height / r.perp_dist);
		r.draw_start = -r.line_height / 2 + game->win_height / 2;
		r.draw_end = r.line_height / 2 + game->win_height / 2;

		// ⚠️ Clampeo
		if (r.draw_start < 0)
			r.draw_start = 0;
		if (r.draw_end >= game->win_height)
			r.draw_end = game->win_height - 1;

		// 🔵 Techo
		game->color = 0x3333FF;
		draw_vertical_line(game, x, 0, r.draw_start - 1);

		// 🟩 Pared
		game->color = 0x00FF00;
		draw_vertical_line(game, x, r.draw_start, r.draw_end);

		// 🟫 Suelo
		game->color = 0x996633;
		draw_vertical_line(game, x, r.draw_end + 1, game->win_height - 1);

		x++;
	}
}








