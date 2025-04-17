#include "../../cub3d.h"

// Pinta una línea vertical en x desde y0 a y1 de un solo color
void	draw_vertical_line(t_game *game, int x, int y0, int y1, int color)
{
	int	y;

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
