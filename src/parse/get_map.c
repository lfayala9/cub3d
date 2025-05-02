#include "../../cub3d.h"

int	is_map_line(char *line)
{
	int	i = 0;

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		get_lines(t_game *g, int map_count, int map_start, char **copy)
{
	int	i;

	i = 0;
	while (i < map_count)
	{
		g->map[i] = ft_strdup(copy[map_start + i]);
		i++;
	}
	g->map[map_count] = NULL;
}

void	get_map(t_game *g, char **copy)
{
	int		i;
	int		map_start;
	int		map_count;

	i = 0;
	map_count = 0;
	map_start = -1;
	while (copy[i])
	{
		if (is_map_line(copy[i]))
		{
			map_start = i;
			break;
		}
		i++;
	}
	if (map_start == -1)
		exit_error("Error: No se encontró el mapa en el archivo", 1, g);
	while (copy[map_start + map_count] && \
			is_map_line(copy[map_start + map_count]))
		map_count++;
	g->map = malloc(sizeof(char *) * (map_count + 1));
	if (!g->map)
		exit_error("Error: fallo al asignar memoria para el mapa", 1, g);
	get_lines(g, map_count, map_start, copy);
}
