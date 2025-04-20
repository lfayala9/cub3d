/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mock_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurodrig <aurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:51:52 by aurodrig          #+#    #+#             */
/*   Updated: 2025/04/20 16:52:00 by aurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

/*
** Retorna un mapa hardcodeado igual al de test_map.cub
** Esto es solo para pruebas iniciales antes del parser real
*/

char **mock_map(void)
{
	char **map = malloc(sizeof(char *) * 8);
	if (!map)
		return (NULL);

	map[0] = "1111111111";
	map[1] = "1000000001";
	map[2] = "1000110001";
	map[3] = "1000000001";
	map[4] = "1000000001";
	map[5] = "1000N00001";
	map[6] = "1111111111";
	map[7] = NULL;

	return (map);
}
