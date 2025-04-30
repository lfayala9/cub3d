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

void	init_elements(char **str, char *element, int n)
{
	*str = malloc(ft_strlen(element) + 1);
	if (!(*str))
		return ;
	copy_str(*str, element, n);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (check_input(ac, av) != 0)
		exit(EXIT_FAILURE);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	game->e = malloc(sizeof(t_element));
	if (!game->e)
		return (1);
	game->elements = malloc(sizeof(char *) * 6);
	parse_data(game, av[1]);
	printf("%s\n", game->e->c_rgb);
	// get_elements(game, av[1]);
	// printf("%s\n", game->elements[0]);
	// printf("%s\n", game->elements[1]);
	// printf("%s\n", game->elements[2]);
	// printf("%s\n", game->elements[3]);
	// printf("%s\n", game->elements[4]);
	// printf("%s\n", game->elements[5]);
	// game->map = mock_map(); // o tu parseo real si ya lo tienes
	// game->player_x = 4.5;
	// game->player_y = 5.5;
	// game->dir_x = 0;
	// game->dir_y = -1;
	// game->plane_x = 0.66;
	// game->plane_y = 0;

	// // Inicializa todo
	// // init_mlx(game);
	// start_game(game);

	// // 🔑 Hooks de teclado
	// mlx_hook(game->mlx_win, 2, 1L<<0, handle_key_press, game);     // keydown
    // mlx_hook(game->mlx_win, 3, 1L<<1, handle_key_release, game);   // keyup

	free(game);
	return (0);
}


