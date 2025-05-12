/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:54:10 by aurodrig          #+#    #+#             */
/*   Updated: 2025/05/12 16:34:41 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	draw_frame(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->mlx_win);
	raycast(game);
	return (0);
}

double	ft_abs(double x)
{
	if (x < 0)
		return -x;
	return x;
}
