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

int	parse_data(t_game *g, char *file)
{
	int	i;

	i = 0;
	get_elements(g, file);
	while (i < 6)
	{
		if (ft_strncmp("WE", g->elements[i], 2) == 0)
			init_elements(&(g->e->we_tx), g->elements[i], 3);
		if (ft_strncmp("EA", g->elements[i], 2) == 0)
			init_elements(&(g->e->ea_tx), g->elements[i], 3);
		if (ft_strncmp("SO", g->elements[i], 2) == 0)
			init_elements(&(g->e->so_tx), g->elements[i], 3);
		if (ft_strncmp("NO", g->elements[i], 2) == 0)
			init_elements(&(g->e->no_tx), g->elements[i], 3);
		if (ft_strncmp("F", g->elements[i], 1) == 0)
			init_elements(&(g->e->f_rgb), g->elements[i], 2);
		if (ft_strncmp("C", g->elements[i], 1) == 0)
			init_elements(&(g->e->c_rgb), g->elements[i], 2);
		i++;
	}
	return (0);
}
