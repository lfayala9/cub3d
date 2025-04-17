#include "../../cub3d.h"

void init_mlx(t_game *game)
{
    game->win_width = 640;
    game->win_height = 480;

    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        ft_putendl_fd("Error\nMLX init failed", 2);
        exit(1);
    }

    game->mlx_win = mlx_new_window(
        game->mlx_ptr,
        game->win_width,
        game->win_height,
        "cub3D"
    );
    if (!game->mlx_win)
    {
        ft_putendl_fd("Error\nWindow creation failed", 2);
        exit(1);
    }
}
