/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:51:17 by layala-s          #+#    #+#             */
/*   Updated: 2025/04/20 17:04:29 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_putendl_fd("Error\nUsage: ./cub3d <map_file.cub>", 2);
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putendl_fd("Error\nMemory allocation failed", 2);
		return (1);
	}

	game->map = mock_map(); // o tu parseo real si ya lo tienes
	game->player_x = 4.5;
	game->player_y = 5.5;
	game->dir_x = 0;
	game->dir_y = -1;
	game->plane_x = 0.66;
	game->plane_y = 0;

	// Inicializa todo
	// init_mlx(game);
	start_game(game);

	// 🔑 Hooks de teclado
	mlx_hook(game->mlx_win, 2, 1L<<0, handle_key_press, game);     // keydown
    mlx_hook(game->mlx_win, 3, 1L<<1, handle_key_release, game);   // keyup

	free(game);
	return (0);
}


