#include "cub3d.h"

int main(int ac, char **av)
{
    t_data game;

    game = NULL;
    if (ac != 2)
       return 0;
    else
    {
        check(av);
        game = malloc(sizeof(t_data));
        if (!game)
            return (NULL);
        
    }
}