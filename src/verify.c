#include "cub3d.h"

static char *get_whole_map(char **av)
{
    int     fd;
    char    **ret;

    fd = open(av[1], O_RDONLY);

}

void check_map_content(char **av, t_data *game)
{
    char **tmp;

    tmp = get_whole_map(av);
}