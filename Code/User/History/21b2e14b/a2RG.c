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
        write(1, "ici", 3);
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
                write(1, "la", 2);
                draw = !draw;
            default :
                continue;
        }
        if (draw) {
            write(1, "lo", 2);
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

int count_neigbour (int bi, int bj, t_map *map) {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0)
                continue;
            int fini = bi + i;
            int finj = bj + j;
            if (fini > 0 && fini < map->height && finj > 0 && finj < map->width)
                if (map->map[fini][finj] == '0')
                    count++;
        }
    }
    return count;
}

bool solve(t_map *map) {
    char **next_map;
    next_map = malloc(map->height * sizeof(char *));
    if (!next_map)
        return false;
    for (int i = 0; i < map->height; i++) {
        next_map[i] = malloc (sizeof(char) * map->width);
        if (!map->map[i])
            return (free_board, false);
    }
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            int n = count_neigbour(i, j, map);
            if (map->map[i][j] == '0') {
                if (n == 2 || n == 3)
                    next_map[i][j] = 'O';
                else
                    next_map[i][j] = ' ';
            }
            else {
                if (n == 3)
                    next_map[i][j] = '0';
                else
                    next_map[i][j] = ' ';
            }
        }
    }
    free_board(map);
    map->map = next_map;
    return true;
}

void print_map(t_map *map) {
    for (int i = 0; i < map->height; i++) {
        for (int j = 0; j < map->width; j++) {
            putchar(map->map[i][j]);
        }
        putchar('\n');
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
        if (!solve(&map))
            return 1;
    }
    print_map(&map);
    free_board(&map);
    return 0;
}