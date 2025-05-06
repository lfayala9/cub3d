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
		return (NULL);
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

	if (check_input(ac, av) != 0)
		exit(EXIT_FAILURE);
	game = init_struct(game);
	if (!game)
		return (1);
	temp = copy_file(av[1]);
	parse_data(game, av[1]);
	get_map(game, temp);
	validate_map(game);
	start_game(game);
	free_game(game);
	return (0);
}
