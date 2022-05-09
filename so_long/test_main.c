#include <stdlib.h>
#include <stdio.h>
#include <string.h>   	
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_data 
{
    int i;
    char *nom;
    int x_max;
}   t_data;

void    ft_init_map(t_data *map)
{  
    map->x_max = 42;
}

// char    *ft_test(char *nom, t_data map)
// {
//     static char *name;

//     map.i = 4;
//     name = "Laurent";
//     return (name);
// }

int main(void)
{
    t_data  world;
    t_data  *map;
    char *nom;
    
    map = &world;
    ft_init_map(map);
    // //nom = "Bryan";
    // nom = ft_test(nom, map);
    printf("%d\n%s", map->x_max, nom);
    return (0);
}