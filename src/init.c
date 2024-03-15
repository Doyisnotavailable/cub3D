#include "cub3d.h"

void init_mlx(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr== NULL)
		ft_putstr_fd("Error: Can't initialize mlx\n", 2);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIDTH, HEIGHT, "cub3D");
	if (!game->win_ptr)
		ft_putstr_fd("Error: Can't initialize window\n", 2);

	game->fbuffer.ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->fbuffer.adr = mlx_get_data_addr(fbuffer.ptr, &fbuffer.bpp, &fbuffer.len, &fbuffer.endian);
}

// void init_buffer(t_data *game)
// {
// 	game->fbuffer.ptr = mlx_new_image(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
// 	game->fbuffer.adr = mlx_get_data_addr(fbuffer.ptr, &fbuffer.bpp, &fbuffer.len, &fbuffer.endian);
	
// }