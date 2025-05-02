
#include "../cub3d.h"

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