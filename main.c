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

void	check_element_value(char *s, int n, t_game *g)
{
	int	i;

	i = 0;
	if (n == 3)
	{
		if (!check_extension(s, ".xpm"))
			exit_error("Error: texture file should be <texture_path.xpm>", \
			1, g);
	}
	if (n == 2)
	{
		while (s[i])
		{
			if (s[i] == '-')
				exit_error("Error: RGB should have positive numeric values", \
				1, g);
			i++;
		}
	}
}

void	init_elements(char **str, char *element, int n, t_game *g)
{
	char	*s;
	int		i;

	*str = malloc(ft_strlen(element) + 1);
	if (!(*str))
		return ;
	s = *str;
	copy_str(*str, element, n);
	check_element_value(s, n, g);
}
t_game	*init_game(t_game *game)
{
	int	i;

	i = 0;
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->e = malloc(sizeof(t_element));
	if (!game->e)
		return (NULL);
	game->elements = malloc(sizeof(char *) * 6);
	while (i < 6)
		game->elements[i++] = 0;
	game->map = mock_map();
	game->e->ea_tx = NULL;
    game->e->we_tx = NULL;
    game->e->so_tx = NULL;
    game->e->no_tx = NULL;
    game->e->c_rgb = NULL;
    game->e->f_rgb = NULL;
	game->player_x = 4.5;
	game->player_y = 5.5;
	game->dir_x = 0;
	game->dir_y = -1;
	game->plane_x = 0.66;
	return (game->plane_y = 0 ,game);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (check_input(ac, av) != 0)
		exit(EXIT_FAILURE);
	game = init_game(game);
	if (!game)
		return (1);
	parse_data(game, av[1]);
	start_game(game);
	free_game(game);
	return (0);
}


