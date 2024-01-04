#include "cub3d.h"

static char **remove_nl(char **map);

void edit_map(t_data *game)
{
    game->map = remove_nl(game->map);
    print_array(game->map);
    exit(1);
}

char **remove_nl(char **map)
{
    int     i;
    int     j;
    char    **ret;

    i = -1;
    j = 0;
    ret = (char**)malloc(sizeof(char *) * (1 + count_line_map(map)));
    while (map[++i])
    {
        while (ft_space_line(map[i]))
            i++;
        while (!ft_space_line(map[i]))
        {    
            ret[j] = ft_substr(map[i], 0, (ft_strlen(map[i]) - count_end_space(map[i]))); // trim the ends too change to substr get len of the whole string without the spaces in the end
            i++;
            j++;
        }
        ret[j] = NULL;
        break ;
    }
    free_array(map);
    return (ret);
}



/* int check_enclosed(char **map, int x, int y)
{

}


11111111111111111111
11111111111111111111
111111111   11111111
111111111   11111111
111  11111111111  11
111  11111111111  11 */