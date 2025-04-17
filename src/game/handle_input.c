#include "../../cub3d.h"

void	handle_input(t_game *game)
{
	// 🔼 Adelante (W)
	if (game->keys[XK_w])
	{
		double new_x = game->player_x + game->dir_x * 0.05;
		double new_y = game->player_y + game->dir_y * 0.05;

		if (game->map[(int)new_y][(int)game->player_x] != '1')
			game->player_y = new_y;
		if (game->map[(int)game->player_y][(int)new_x] != '1')
			game->player_x = new_x;
	}

	// 🔽 Atrás (S)
	if (game->keys[XK_s])
	{
		double new_x = game->player_x - game->dir_x * 0.05;
		double new_y = game->player_y - game->dir_y * 0.05;

		if (game->map[(int)new_y][(int)game->player_x] != '1')
			game->player_y = new_y;
		if (game->map[(int)game->player_y][(int)new_x] != '1')
			game->player_x = new_x;
	}

	// ⬅️ Strafe izquierda (A)
	if (game->keys[XK_a])
	{
		double new_x = game->player_x - game->plane_x * 0.05;
		double new_y = game->player_y - game->plane_y * 0.05;

		if (game->map[(int)new_y][(int)game->player_x] != '1')
			game->player_y = new_y;
		if (game->map[(int)game->player_y][(int)new_x] != '1')
			game->player_x = new_x;
	}

	// ➡️ Strafe derecha (D)
	if (game->keys[XK_d])
	{
		double new_x = game->player_x + game->plane_x * 0.05;
		double new_y = game->player_y + game->plane_y * 0.05;

		if (game->map[(int)new_y][(int)game->player_x] != '1')
			game->player_y = new_y;
		if (game->map[(int)game->player_y][(int)new_x] != '1')
			game->player_x = new_x;
	}

    	// 🔄 Rotar a la izquierda
	if (game->keys[XK_Right])
	{
		double old_dir_x = game->dir_x;
		double old_plane_x = game->plane_x;
		double rot_speed = 0.05;

		game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
		game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);

		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
		game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
	}

	// 🔄 Rotar a la derecha
	if (game->keys[XK_Left])
	{
		double old_dir_x = game->dir_x;
		double old_plane_x = game->plane_x;
		double rot_speed = -0.05; // nota el signo negativo

		game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
		game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);

		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
		game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
	}


	// 🐾 Debug pos
	//printf("🚶‍♂️ Posición actual: (%.2f, %.2f)\n", game->player_x, game->player_y);
}




int	handle_key_press(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
    {
		game->keys[keycode] = 1;
        printf("🔑 Tecla presionada: %d\n", keycode);  // 👈 DEBUG
    }
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(game->mlx_ptr, game->mlx_win);
		exit(0);
	}
	return (0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode >= 0 && keycode < MAX_KEYS)
    {
		game->keys[keycode] = 0;
       printf("🛑 Tecla soltada: %d\n", keycode);  // 👈 DEBUG
    }
	return (0);
}
