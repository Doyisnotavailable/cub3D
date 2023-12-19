#include "cub3d.h"

t_img	xpm_img(void *mlx, char *path, t_game *game)
{
	t_img	model;

	(void)game;
	model.img = mlx_xpm_file_to_image(mlx, path, &model.x, &model.y);
	if (model.img == NULL)
	{
		ft_putstr_fd("Error\nInvalid XPM file\n", 2);
		destroy_img(game);
		mlx_destroy_window(game->mlx, game->win);
		free(game->mlx);
	}
	return (model);
}