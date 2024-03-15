#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

