#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct {
    char **map;
    int width;
    int height;
    int iteration;
} t_map;

void fill_map(t_map *map) {
    char a;
    int i = 0;
    int j = 0;
    bool draw = false;
    while (read(0, &a, 1) == 1) {
        switch (a) {
            case 'w':
                if (j > 0)
                    j--;
                break;
            case 'a':
                if (i > 0)
                    i--;
                break;
            case 's':
                if (j < map->height - 1)
                    j++;
                break;
            case 'd':
                if (i < map->width - 1)
                    i++;
                break;
            case 'x' :
                draw = !draw;
            default :
                continue;
        }
        if (draw) {
            map->map[j][i] = '0';
        }
    }
}

void free_board(t_map *map) {
    for (int i = 0; i < map->height; i++) {
        if (map->map[i])
            free(map->map[i]);
    }
    if (map->map)
        free(map->map);
}

bool init(t_map *map, char **av) {
    map->width = atoi(av[1]);
    map->height = atoi(av[2]);
    map->iteration = atoi(av[3]);
    map->map = malloc(sizeof(char*) * map->height);
    if (!map->map)
        return false;
    for (int i = 0; i < map->height; i++) {
        map->map[i] = malloc(sizeof(char) * map->width);
        if (!map->map[i])
            return (free_board(map), false);
        for (int j = 0; j < map->width; j++) {
            map->map[i][j] = ' ';
        }
    }
    return true;
}

void solve(t_map *map) {

}

void print_map(t_map *map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            putchar(map->map[i][j]);
        }
    }
}

int main(int ac, char **av) {
    if (ac != 4)
        return 1;
    t_map map;
    if (!init(&map, av)) {
        return 1;
    }
    fill_map(&map);

    for (int i = 0; i < map.iteration; i++) {
        solve(&map);
    }
    print_map(&map);
    free_board(&map);
    return 0;
}