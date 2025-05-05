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

int check_borders(char **map)
{
    int i;
    int x;
    int y;

    i = 0;
    x = 0;
    while (map[x])
        x++;
    y = ft_strlen(map[0]);
    while (i < y)
    {
        if (map[0][i] != '1' || map[x - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < x)
    {
        if (map[i][0] != '1' || map[y - 1][i] != '1')
            return (0);
        i++;
    }
    return (1);
}

void    validate_map(t_game *g)
{
    if (check_borders(g->map) == 0)
        exit_error("Invalid map", 1, g);
}