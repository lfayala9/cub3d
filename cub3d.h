/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:42:32 by layala-s          #+#    #+#             */
/*   Updated: 2025/04/14 14:42:34 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*INCLUDES*/

# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

/*TYPES*/

typedef struct  s_game  t_game;

/*STRUCTS*/

struct  s_game
{
    void    *mlx_win;
    void    *mlx_ptr;
    int     win_width;
    int     win_height;
};

#endif