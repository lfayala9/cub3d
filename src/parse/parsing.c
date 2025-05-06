/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:05:50 by layala-s          #+#    #+#             */
/*   Updated: 2025/04/20 16:05:51 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	copy_str(char *dest, char*src, int n)
{
	if (n >= ft_strlen(src))
		dest[0] = '\0';
	else
		ft_strcpy(dest, src + n);
}

int	check_data(t_game *g, char *file)
{
	int			i;
	int			found[6];

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp("1", g->elements[i], 1) == 0)
			exit_error("Error: Map is in the middle of the file", 1, g);
		else if (ft_strncmp("NO ", g->elements[i], 3) == 0)
			found[0]++;
		else if (ft_strncmp("SO ", g->elements[i], 3) == 0)
			found[1]++;
		else if (ft_strncmp("WE ", g->elements[i], 3) == 0)
			found[2]++;
		else if (ft_strncmp("EA ", g->elements[i], 3) == 0)
			found[3]++;
		else if (ft_strncmp("F ", g->elements[i], 2) == 0)
			found[4]++;
		else if (ft_strncmp("C ", g->elements[i], 2) == 0)
			found[5]++;
		else
			exit_error("Error: Element should be WE EA SO NO C F", 1, g);
		i++;
	}
	return (0);
}

int	parse_data(t_game *g, char *file)
{
	int	i;

	i = 0;
	get_elements(g, file);
	check_data(g, file);
	while (i < 6)
	{
		if (ft_strncmp("WE", g->elements[i], 2) == 0)
			init_elements(&(g->e->we_tx), g->elements[i], 3, g);
		if (ft_strncmp("EA", g->elements[i], 2) == 0)
			init_elements(&(g->e->ea_tx), g->elements[i], 3, g);
		if (ft_strncmp("SO", g->elements[i], 2) == 0)
			init_elements(&(g->e->so_tx), g->elements[i], 3, g);
		if (ft_strncmp("NO", g->elements[i], 2) == 0)
			init_elements(&(g->e->no_tx), g->elements[i], 3, g);
		if (ft_strncmp("F", g->elements[i], 1) == 0)
			init_elements(&(g->e->f_rgb), g->elements[i], 2, g);
		if (ft_strncmp("C", g->elements[i], 1) == 0)
			init_elements(&(g->e->c_rgb), g->elements[i], 2, g);
		i++;
	}
	return (0);
}

int	check_values(char **map, t_game *g)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (check_player_and_limits(map, x, y, g) != 0)
				return (1);
			if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != ' ' \
				&& map[x][y] != '\t' && map[x][y] != '\n' && map[x][y] != 'S' \
				&& map[x][y] != 'N' && map[x][y] != 'E' && map[x][y] != 'W')
				return (1);
		}
	}
	if (check_edges(map))
		return (1);
	return (0);
}
