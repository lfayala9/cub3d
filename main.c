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

void	safe_free(t_game *g)
{
	int	i;

	if (!g)
		return ;
	if (g->map)
	{
		i = 0;
		while (g->map[i])
			free(g->map[i++]);
	}
	if (g->e)
	{
		free(g->e->ea_tx);
		free(g->e->we_tx);
		free(g->e->so_tx);
		free(g->e->no_tx);
		free(g->e->c_rgb);
		free(g->e->f_rgb);
	}
	if (g->elements)
	{
		i = 0;
		while (i < 6)
			free(g->elements[i++]);
	}
}

char	**copy_file(const char *filename)
{
	int		fd;
	int		line_count;
	char	*line;
	char	**temp;

	temp = malloc(sizeof(char *) * 1024);
	if (!temp)
		return (NULL);
	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free(temp), NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp[line_count++] = line;
		line = get_next_line(fd);
	}
	temp[line_count] = NULL;
	close(fd);
	return (temp);
}

int	main(int ac, char **av)
{
	t_game	*game;
	char	**temp;
	int		i;

	if (check_input(ac, av) != 0)
		exit(EXIT_FAILURE);
	game = init_struct(game);
	if (!game)
		return (1);
	i = 0;
	while (game->keys[i] < MAX_KEYS)
		game->keys[i++] = 0;
	temp = copy_file(av[1]);
	if (!temp)
		exit_error("Error: Can't find .cub file", 1, game);
	get_map(game, temp);
	parse_data(game, temp);
	validate_map(game);
	start_game(game);
	free_game(game);
	return (0);
}
