
#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data		game;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n Invalid Syntax ./cub3d 'MAP_PATH'", 2);
		return (0);
	}
	check(av, &game);
}