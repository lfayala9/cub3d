#include "../../cub3d.h"


int	draw_frame(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	raycast(game);
	return (0);
}




