/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:21 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 16:19:40 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../inc/libft/libft.h"
# include "../inc/printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>

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

	t_tmp			tmp;
	t_img			n_img;
	t_img			e_img;
	t_img			w_img;
	t_img			s_img;
	t_rgb			floor;
	t_rgb			sky;

}	t_data;

// init_utils.c
t_img		xpm_img(void *mlx, char *path, t_data *game);
int			ft_space(char c);
int			ft_space_line(char *str);

// init_game.c
void		*img_ptr(t_data *game);
void		init_errthang(t_data *game);
void		init_mlx_ptr(t_data *game);

// free.c
void		destroy_img(t_data *game);
void	free_array(char **str);

// check.c
void		check(char **av, t_data *game);

// verify.c
void		check_map_content(char **av, t_data *game);

// verify_utils.c
char		**ft_split_tab(char const *s, char c);
char		*copy_and_free(char **tmp);
int			count_array(char **s);

// check_elements.c
void		check_elements(t_data *game);


// utils for testing testing_utils.c
void	print_array(char **str);

#endif