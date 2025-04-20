#include "../../cub3d.h"

// ⚙️ Esta función se llama constantemente por mlx_loop_hook
int	game_loop(t_game *game)
{
	handle_input(game);   // 🕹️ Detectar teclas
	raycast(game);        // 👁️ Dibujar escena
	return (0);
}


// 🧨 Esta arranca la ventana y entra al loop
void	start_game(t_game *game)
{
	game->win_width = 640;
	game->win_height = 480;

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(1);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_width, game->win_height, "cub3D");
	if (!game->mlx_win)
		exit(1);

	// 🧠 Hook de teclas
	mlx_hook(game->mlx_win, 2, 1L << 0, handle_key_press, game);   // key down
	mlx_hook(game->mlx_win, 3, 1L << 1, handle_key_release, game); // key up

	// 🔁 Bucle principal
	mlx_loop_hook(game->mlx_ptr, game_loop, game);
	mlx_loop(game->mlx_ptr);
}

