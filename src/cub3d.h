/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:21 by mlumibao          #+#    #+#             */
/*   Updated: 2024/03/06 16:15:39 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

# define WIDTH			1080
# define HEIGHT			720
# define NO				1
# define EA				2
# define WE				3
# define SO				4
# define F				5
# define C				6
# define TEXSIZE		64
# define MS				0.00125 //movespeed
# define RS				0.02 //rotate speed

typedef struct s_draw
{
	int		lineH;
	int		drawStart;
	int		drawEnd;
	int		pitch;
	double	wallX;
	int		texcoord;
	double	step;
	double	texpos;

}	t_draw;
typedef struct s_player
{
	char	facing;
	int		x;
	int		y;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
} t_player;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_img
{
	char		*path;
	int			x;
	int			y;
}	t_img;

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		win_width;
	int		win_length;
}	t_mlx;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
}	t_map;

typedef struct s_tmp
{
	char			*n_path;
	char			*e_path;
	char			*w_path;
	char			*s_path;
	char			*f;
	char			*c;
}	t_tmp;

typedef struct s_var
{
	// int		fd;
	// char	*line_from_map;
	// char	*line;
	// int		n_prev_line_elems;
	// char	**splitted_line;
	// int		current_elems;

	float	x;
	float	y;
	float	x1;
	float	y1;
	int		z;
	int		z1;
}	t_var;

typedef struct s_ray
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
} t_ray;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				color;
	int				row;
	int				column;
	int				z_scale;
	t_mlx			mlx;
	t_var			vars;

	t_ray			ray;
	t_map			map;
	t_player		player; // added this struct for storing player facing direction, and player position.
	uint32_t		floorc; //converted 3int to one
	uint32_t		skyc; //converted 3int to one
	int				draw_flag;

	t_img			n_img;
	t_img			e_img;
	t_img			w_img;
	t_img			s_img;
	t_rgb			floor;
	t_rgb			sky;
	
	t_tmp			tmp;
}	t_data;

// init_utils.c
t_img		xpm_img(void *mlx, char *path, t_data *game);
int			ft_space(char c);
int			ft_space_line(char *str);
void		init_tmp(t_data *game);
void		init_rgb(t_data *game);
int			file_line_count(char **av);

// init_game.c
void		*img_ptr(t_data *game);
void		init_errthang(t_data *game);
void		init_mlx_ptr(t_data *game);

// free.c
void		destroy_img(t_data *game);
void		free_array(char **str);
void		free_array_exit(char **tmp, char *str);

// check.c
void		check(char **av, t_data *game);

// get_file.c
void		check_file_content(char **av, t_data *game);

// verify.c
void		check_map_line(t_data *game, int *size);
void		verify_map(t_data *game);
int			check_map_char(t_data *game, int *i);
void		check_map_walls(t_data *game, int size);

// verify_utils.c
char		**ft_split_tab(char const *s, char c);
char		*copy_and_free(char **tmp);
int			count_array(char **s);

// check_elements.c
void		check_elements(t_data *game);
void		store_to_rgb(t_data *game, char *str, int type);
void		check_hex(t_data *game, char **tmp, int type);

// scan_utils.c
void		get_store_map(char **file, t_data *game);
char		**scan_map(char **file);

// element_utils.c
int			check_comma(char *str);
int			check_valid_char(char *str);
long		ft_atol(char *str);

// map_edit.c
void		edit_map(t_data *game);
int			check_enclosed_space(char **map);
int			check_enclosed_zero(char **map);

// map_utils.c
int			count_end_space(char *map);
int			count_line_map(char **map);
int			count_line_col(char **map, int col);

// utils for testing testing_utils.c
// void		print_array(char **str);
void		print_array(t_data *data);
void		print_tmp(t_data *game);
void		free_tmp(t_data *game);
void		print_rgb(t_data *game);

// check_map_utils.c for checking bounderies of 0 and spaces
int			check_left_right_zero(char **map, int x, int y);
int			check_up_down_zero(char **map, int x, int y);
int			check_left_right_space(char **map, int x, int y);
int			check_up_down_space(char **map, int x, int y);
int			ft_valid_char(char c);

// added latest final_parse.c
void		color(t_data *game);
void		getplayerpos(t_data *game);
void		finaladd(t_data *game);

// added latest rect_map.c
void 		rect_map(t_data *game);

// added latest raycast.c
void		calc_ray(t_data *game);
void		calc_step(t_data *game);
void		dda(t_data *game);
void		draw_ray(t_data *game, t_draw *draw, int i);
void		perp(t_data *game, int i);

// added keymap.c
int			key_rotate(int keycode, t_data *game);
int			key_move(int keycode, t_data *game);

void	use_mlx(t_data *data);
void	init_var(t_data *data);
int		close_win(t_data *data);
void	fullscreen_win(int key, t_data *data);
void	resize_win(int key, t_data *data);
int		esc_win(int key, t_data *data);
int		key_hooks(int keycode, t_data *data);
void    draw_map(t_data *data);
void 	count_rows_columns(t_data *data);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);


#endif