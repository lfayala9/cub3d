#include "../../cub3d.h"


void	draw_vertical_line(t_game *game, int x, int y0, int y1, int color)
{
	int y;

	if (y0 < 0)
		y0 = 0;
	if (y1 >= game->win_height)
		y1 = game->win_height - 1;

	y = y0;
	while (y <= y1)
	{
		mlx_pixel_put(game->mlx_ptr, game->mlx_win, x, y, color);
		y++;
	}
}

// Valor absoluto sin usar fabs
double	ft_abs(double x)
{
	if (x < 0)
		return -x;
	return x;
}

// Raycaster completo con techo, pared y suelo
void	raycast(t_game *game)
{
	//printf("👉 raycast ejecutándose\n");  // 👈 DEBUG
	int		x;
	double	camera_x;
	double	ray_x;
	double	ray_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	x = 0;
	while (x < game->win_width)
	{
		// 1️⃣ Dirección del rayo
		camera_x = 2.0 * x / game->win_width - 1.0;
		ray_x = game->dir_x + game->plane_x * camera_x;
		ray_y = game->dir_y + game->plane_y * camera_x;

		map_x = (int)(game->player_x);
		map_y = (int)(game->player_y);

		if (ray_x == 0)
			delta_x = 1e30;
		else
			delta_x = ft_abs(1.0 / ray_x);
		if (ray_y == 0)
			delta_y = 1e30;
		else
			delta_y = ft_abs(1.0 / ray_y);

		// 2️⃣ Steps y side distances
		if (ray_x < 0)
		{
			step_x = -1;
			side_x = (game->player_x - map_x) * delta_x;
		}
		else
		{
			step_x = 1;
			side_x = (map_x + 1.0 - game->player_x) * delta_x;
		}
		if (ray_y < 0)
		{
			step_y = -1;
			side_y = (game->player_y - map_y) * delta_y;
		}
		else
		{
			step_y = 1;
			side_y = (map_y + 1.0 - game->player_y) * delta_y;
		}

		// 3️⃣ DDA
		hit = 0;
		while (hit == 0)
		{
			if (side_x < side_y)
			{
				side_x += delta_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_y += delta_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map[map_y][map_x] == '1')
				hit = 1;
		}

		// 4️⃣ Distancia perpendicular al muro
		if (side == 0)
			perp_dist = (map_x - game->player_x + (1 - step_x) / 2.0) / ray_x;
		else
			perp_dist = (map_y - game->player_y + (1 - step_y) / 2.0) / ray_y;

		// 5️⃣ Tamaño y posición de la pared
		line_height = (int)(game->win_height / perp_dist);
		draw_start = -line_height / 2 + game->win_height / 2;
		draw_end = line_height / 2 + game->win_height / 2;

		// ⚠️ Clampeo
		if (draw_start < 0)
			draw_start = 0;
		if (draw_end >= game->win_height)
			draw_end = game->win_height - 1;

		// 🔵 Techo
		draw_vertical_line(game, x, 0, draw_start - 1, 0x3333FF); // Azul

		// 🟩 Pared
		draw_vertical_line(game, x, draw_start, draw_end, 0x00FF00); // Verde

		// 🟫 Suelo
		draw_vertical_line(game, x, draw_end + 1, game->win_height - 1, 0x996633); // Marrón

		x++;
	}
}
