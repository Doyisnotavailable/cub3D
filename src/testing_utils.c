#include "cub3d.h"
#include <stdio.h>

void	print_array(char **str)
{
	int	i = 0;

	while(str[i])
	{
		printf("%s", str[i]);
		i++;
	}
}

void	print_tmp(t_data *game)
{
	if (game->tmp.n_path)
		printf("%s\n", game->tmp.n_path);
	if (game->tmp.e_path)
		printf("%s\n", game->tmp.e_path);
	if (game->tmp.w_path)
		printf("%s\n", game->tmp.w_path);
	if (game->tmp.s_path)
		printf("%s\n", game->tmp.s_path);
	if (game->tmp.f)
		printf("%s\n", game->tmp.f);
	if (game->tmp.e_path)
		printf("%s\n", game->tmp.c);
}