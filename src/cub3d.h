#ifndef CUB3D_H
# define CUB3D_H

#include "../inc/libft/libft.h"
#include "../inc/printf/ft_printf.h"
#include <stdlib.h>
#include <fcntl.h>

#define WIDTH       1080
#define HEIGHT      720

typedef struct s_img
{
    void		*img;
	int			x;
	int			y;
} t_img;

typedef struct s_map
{
    char **map;
    
}   t_map;
typedef struct s_data
{
    //map and mlx pointers;
    char            **map;
    void            *mlx;
    void            *win;

    //pointer for wall textures
    t_img            *N_IMG;
    t_img            *E_IMG;
    t_img            *W_IMG;
    t_img            *S_IMG;

} t_data;

// init_utils.c
t_img   	xpm_img(void *mlx, char *path, t_game *game);

// init_game.c
void        *img_ptr(t_data *game);
void        init_errthang(t_data *game);
void        init_mlx_ptr(t_data *game);

// free.c
void        destroy_img(t_data *game);

// check.c
void    check(char **av, t_data *game);
# endif