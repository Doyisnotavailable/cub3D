#include "cub3d.h"

int count_end_space(char *map)
{
    int ret;
    int len;

    len = ft_strlen(map);
    ret = 0;
    while (len >= 0)
    {
        while (map[len] == ' ' || map[len] == '\t')
        {
            len--;
            ret++;
        }
        return (ret);
    }
    return (ret);
}

int count_line_map(char **map)
{
    int i;
    int ret;

    ret = 0;
    i = 0;
    while (map[i])
    {
        while (ft_space_line(map[i]))
            i++;
        while (!ft_space_line(map[i++]))
            ret++;
        break ;
    }
    return (ret);
}
