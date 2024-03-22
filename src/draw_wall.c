#include "cub3d.h"

int get_wall_direction(t_data *game)
{
	if (game->ray.side == 0)
	{
		if (game->ray.rayDirX < 0)
			return 1;
		return 2;
	}
	else
	{
		if (game->ray.rayDirY > 0)
			return 3;
		else
			return 4;
	}
};

/* int get_texture_color(int texNum, int texX, int texY) {
    // Calculate the index of the pixel in the texture data array
    int index = texY * textures[texNum].size_line + texX * (textures[texNum].bpp / 8);

    // Retrieve the color of the pixel from the texture data
    int color = *(int *)(textures[texNum].data + index);

    return color;
} */

int text_color(t_img img, int x, int y)
{
    char    *index;
    int     color;

	index = img.adr + (y * img.len + x * (img.bpp / 8));
    color = *(unsigned int *)(index);
    return (color);
}

void draw_tex(t_data *game, t_draw *draw, int i, t_img img)
{
    int     y;
    int     color;

    if(game->ray.side == 0)
        draw->texpos = game->player.posY + game->ray.perpWallDist * game->ray.rayDirY;
    else
        draw->texpos = game->player.posX + game->ray.perpWallDist * game->ray.rayDirX;
    draw->texpos -= floor(draw->texpos);
    draw->texX = (int)(draw->texpos * TEXSIZE);
    draw->step = 1.0 * TEXSIZE / draw->lineH;
    draw->texpos = (draw->drawStart - HEIGHT / 2 + draw->lineH / 2) * draw->step;

    y = draw->drawStart;
	// printf("texpos = %f\ntexX = %i\nstep = %f\ntexpos = %f\n", draw->texpos, draw->texX, draw->step, draw->texpos);
    while (y < draw->drawEnd)
    {
        draw->texY = (int)draw->texpos & (TEXSIZE - 1);
        draw->texpos += draw->step;
        color = text_color(img, draw->texX, draw->texY);
        my_mlx_pixel_put(&game->fbuffer, i, y, color);
        y++;
    }
}

void draw_wall(t_data *game, t_draw *draw, int i)
{
    int wall;
    
    wall = get_wall_direction(game);

    if (wall == 1)
        draw_tex(game, draw, i, game->e_img);
    else if (wall == 2)
        draw_tex(game, draw, i, game->s_img);
    else if (wall == 3)
        draw_tex(game, draw, i, game->w_img);
    else
        draw_tex(game, draw, i, game->n_img);
}
