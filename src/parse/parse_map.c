/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:31:45 by layala-s          #+#    #+#             */
/*   Updated: 2025/05/05 14:31:47 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_first_last(char **map)
{
	int	i;
	char *f;
	char *l;

	i = 0;
	f = map[0];
	while (f[i])
	{
		if (f[i] != ' ' && f[i] != '\t' && f[i] != '1' && f[i] != '\n')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
		i++;
	l = map[i - 1];
	i = 0;
	while (l[i])
	{
		if (l[i] != ' ' && l[i] != '\t' && l[i] != '1' \
			&& l[i] != '\0' && l[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_player_and_spaces(char **map, int x, int y, t_game *g)
{
	if (map[x][y] == 'S' || map[x][y] == 'W' || \
		map[x][y] == 'E' || map[x][y] == 'N')
		g->p_count++;
	if ((map[x][y] == ' ' || map[x][y] == '\t'))
	{
		if (y > 0 && y + 1 < ft_strlen(map[x]) && x > 0 && map[x + 1])
		{
			if ((map[x][y - 1] != ' ' && map[x][y - 1] != '\t' \
				&& map[x][y - 1] != '1') || \
				(map[x][y + 1] != ' ' && map[x][y + 1] != '\t' \
				&& map[x][y + 1] != '1') || \
				(map[x - 1][y] != ' ' && map[x - 1][y] != '\t' \
				&& map[x - 1][y] != '1') || \
				(map[x + 1][y] != ' ' && map[x + 1][y] != '\t' \
				&& map[x + 1][y] != '1'))
				return (1);
		}
	}
	return (0);
}

int	check_edges(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x])
	{
		y = ft_strlen(map[x]);
		if ((map[x][0] != '1' && map[x][0] != ' ' &&  \
			map[x][0] != '\t' && map[x][0] != '\n') || \
			(map[x][y - 2] != '1' && map[x][y - 2] != ' ' &&  \
			map[x][y - 2] != '\t' && map[x][y - 2] != '\n'))
			printf("%s\n", "error");
		// printf("este es el primer de la fila: %c y este es el ultimo %c %d\n", map[x][0], map[x][y - 2], y);
		x++;
	}
	return (0);
}


int check_values(char **map, t_game *g)
{
    int x;
    int y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (check_player_and_spaces(map, x, y, g) != 0)
				return (1);
			if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != ' ' \
				&& map[x][y] != '\t' && map[x][y] != '\n' && map[x][y] != 'S' \
				&& map[x][y] != 'N' && map[x][y] != 'E' && map[x][y] != 'W')
				return (1);
		}
	}
	if (check_edges(map) != 0)
		return (1);
    return (0);
}

void    validate_map(t_game *g)
{
    if (check_first_last(g->map) != 0 || check_values(g->map, g) != 0)
        exit_error("Error: Invalid map", 1, g);
	if (g->p_count > 1 || g->p_count < 1)
		exit_error("Error: only ONE player character <W, S, N, E>", 1, g);
}