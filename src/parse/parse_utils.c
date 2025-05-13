/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:33:00 by layala-s          #+#    #+#             */
/*   Updated: 2025/05/13 10:33:02 by layala-s         ###   ########.fr       */
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

void	set_direction(t_game *g, char ori)
{
	if (ori == 'N')
	{
		g->dir_x = 0.0;
		g->dir_y = -1.0;
	}
	else if (ori == 'S')
	{
		g->dir_x = 0.0;
		g->dir_y = 1.0;
	}
	else if (ori == 'E')
	{
		g->dir_x = 1.0;
		g->dir_y = 0.0;
	}
	else if (ori == 'W')
	{
		g->dir_x = -1.0;
		g->dir_y = 0.0;
	}
}

void	set_plane(t_game *g, char ori)
{
	if (ori == 'N')
	{
		g->plane_x = 0.66;
		g->plane_y = 0.0;
	}
	else if (ori == 'S')
	{
		g->plane_x = -0.66;
		g->plane_y = 0.0;
	}
	else if (ori == 'E')
	{
		g->plane_x = 0.0;
		g->plane_y = 0.66;
	}
	else if (ori == 'W')
	{
		g->plane_x = 0.0;
		g->plane_y = -0.66;
	}
}
