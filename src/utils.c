/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:57:24 by layala-s          #+#    #+#             */
/*   Updated: 2025/05/05 10:57:30 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

t_game	*init_struct(t_game *game)
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
	game->e->ea_tx = NULL;
	game->e->we_tx = NULL;
	game->e->so_tx = NULL;
	game->e->no_tx = NULL;
	game->e->c_rgb = NULL;
	game->e->f_rgb = NULL;
	game->p_count = 0;
	game->player_x = 0.5;
	game->player_y = 0.5;
	game->dir_x = 0;
	game->dir_y = -1;
	game->plane_x = 0.66;
	return (game->plane_y = 0, game);
}

void	exit_error(char *msg, int code_free, t_game *g)
{
	int	i;

	i = 0;
	printf("%s\n", msg);
	if (code_free == 1)
	{
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
		free(g->elements);
		free(g);
	}
	exit(EXIT_FAILURE);
}
