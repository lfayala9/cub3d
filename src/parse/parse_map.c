/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:31:45 by layala-s          #+#    #+#             */
/*   Updated: 2025/05/06 10:37:15 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_first_last(char **map)
{
	int		i;
	char	*f;
	char	*l;

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

int	check_edges(char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[x])
	{
		y = ft_strlen(map[x]);
		if ((map[x][0] != '1' && map[x][0] != ' ' && \
			map[x][0] != '\t' && map[x][0] != '\n') || \
			(map[x][y - 2] != '1' && map[x][y - 2] != ' ' && \
			map[x][y - 2] != '\t' && map[x][y - 2] != '\n'))
			return (1);
		x++;
	}
	return (0);
}

int	get_limits(char **map, int x, int y)
{
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

int	is_invalid_adjacent(char **map, int x, int y)
{
	if (x > 0)
		if ((int)ft_strlen(map[x - 1]) <= y || \
			map[x - 1][y] == ' ' || map[x - 1][y] == '\t')
			return (1);
	if (map[x + 1] == NULL || (int)ft_strlen(map[x + 1]) <= y \
		|| map[x + 1][y] == ' ' || map[x + 1][y] == '\t')
		return (1);
	if (y > 0 && (map[x][y - 1] == ' ' || map[x][y - 1] == '\t'))
		return (1);
	if (y + 1 >= (int)ft_strlen(map[x]) || \
		map[x][y + 1] == ' ' || map[x][y + 1] == '\t')
		return (1);
	return (0);
}

int	check_player_and_limits(char **map, int x, int y, t_game *g)
{
	if (map[x][y] == 'S' || map[x][y] == 'W' \
		|| map[x][y] == 'E' || map[x][y] == 'N')
	{
		g->p_count++;
		if (is_invalid_adjacent(map, x, y))
			return (1);
	}
	if (map[x][y] == '0')
	{
		if (is_invalid_adjacent(map, x, y))
			return (1);
	}
	if (get_limits(map, x, y))
		return (1);
	return (0);
}
