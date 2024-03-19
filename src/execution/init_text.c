#include "cub3d.h"

t_img	xpm_img(t_data *game, char *path)
{
    printf("xpm_img\n");
	t_img	tex;

	(void)game;
	tex.img = mlx_xpm_file_to_image(game->mlx_ptr, path, &tex.x, &tex.y);
	return (tex);
}

init_tex_adr(t_data *game)
{
    game->n_img.adr = mlx_get_data_addr(game->n_img.ptr, game->n_img.bpp, game->n_img.len, game->n_img.endian);
    game->s_img.adr = mlx_get_data_addr(game->s_img.ptr, game->s_img.bpp, game->s_img.len, game->s_img.endian);
    game->e_img.adr = mlx_get_data_addr(game->e_img.ptr, game->e_img.bpp, game->e_img.len, game->e_img.endian);
    game->w_img.adr = mlx_get_data_addr(game->w_img.ptr, game->w_img.bpp, game->w_img.len, game->w_img.endian);

    if (!game->n_img.adr || !game->s_img.adr || !game->e_img.adr || !game->w_img.adr)
    {
        //free everything then exit
    }
}

init_textures(t_data *game)
{
    game->n_img = xpm_img(game->mlx_ptr, game->tmp.n_path);
    game->s_img = xpm_img(game->mlx_ptr, game->tmp.s_path);
    game->e_img = xpm_img(game->mlx_ptr, game->tmp.e_path);
    game->w_img = xpm_img(game->mlx_ptr, game->tmp.w_path);

    if (!game->n_img.ptr || !game->s_img.ptr || !game->e_img.ptr || !game->w_img.ptr)
    {
        //free everything then exit
    }
    init_tex_adr(game);
}



