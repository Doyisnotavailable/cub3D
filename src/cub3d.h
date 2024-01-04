/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:21 by mlumibao          #+#    #+#             */
/*   Updated: 2024/01/03 21:26:27 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../inc/libft/libft.h"
# include "../inc/printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h> //to remove
# include <limits.h>

# define WIDTH			1080
# define HEIGHT			720
# define NO				1
# define EA				2
# define WE				3
# define SO				4
# define F				5
# define C				6

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_img
{
	void		*img;
	char		*path;
	int			x;
	int			y;
}	t_img;

typedef struct s_map
{
	char		**map;
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

typedef struct s_data
{
	char			**map;
	void			*mlx;
	void			*win;

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

// map_utils.c
int			count_end_space(char *map);
int			count_line_map(char **map);

// utils for testing testing_utils.c
void		print_array(char **str);
void		print_tmp(t_data *game);
void		free_tmp(t_data *game);
void		print_rgb(t_data *game);


#endif