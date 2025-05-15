/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:51:33 by aurodrig          #+#    #+#             */
/*   Updated: 2025/05/06 10:45:05 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	game_loop(t_game *game)
{
	handle_input(game);
	raycast(game);
	return (0);
}

void	free_game(t_game *g)
{
	int	i;

	i = 0;
	free(g->e->ea_tx);
	free(g->e->we_tx);
	free(g->e->so_tx);
	free(g->e->no_tx);
	free(g->e->c_rgb);
	free(g->e->f_rgb);
	free(g->e);
	while (i < 6)
	{
		free(g->elements[i]);
		i++;
	}
	i = 0;
	while (g->map[i])
		free(g->map[i++]);
	free(g->map);
	free(g->elements);
	free(g);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->mlx_win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	start_game(t_game *game)
{
	char	**f_rgb;
	char	**c_rgb;

	f_rgb = get_rgb(game->e->f_rgb, game);
	check_rgb(f_rgb, game);
	free_rgb(f_rgb);
	c_rgb = get_rgb(game->e->c_rgb, game);
	check_rgb(c_rgb, game);
	free_rgb(c_rgb);
	get_position(game);
	game->win_width = WIN_WIDTH;
	game->win_height = WIN_HEIGHT;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(1);
	game->mlx_win = mlx_new_window(game->mlx_ptr, game->win_width, \
	game->win_height, "cub3D");
	if (!game->mlx_win)
		exit(1);
	mlx_hook(game->mlx_win, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, handle_key_release, game);
	mlx_hook(game->mlx_win, 17, 1L << 2, exit_game, game);
	mlx_loop_hook(game->mlx_ptr, game_loop, game);
	mlx_loop(game->mlx_ptr);
}
