// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>
// #include <unistd.h>


// typedef struct {
//     char **board;
//     int row;
//     int cols;
//     int iteration;
// } t_game;

// void free_board(t_game *game) {
//     for (int i = 0; i < game->row; i++) {
//         if (game->board[i])
//             free(game->board[i]);
//     }
//     if (game->board)
//         free(game->board);
// }

// bool init(char **av, t_game *game) {
//     game->row = atoi(av[1]);
//     game->cols = atoi(av[2]);
//     game->iteration = atoi(av[3]);
//     game->board = malloc(game->row * sizeof(char *));
//     if (!game->board)
//         return false;
//     for (int i = 0; i < game->cols; i++) {
//         game->board[i] = malloc(game->cols * sizeof(char));
//         if (!game->board[i]) {
//             free_board(game);
//             return false;
//         }
//         for (int j = 0; j < game->cols; j++) {
//             game->board[i][j] = ' ';
//         }
//     }
//     return true;
// }

// void fill_board(t_game *game) {
//     char buff;
//     int x = 0;
//     int y = 0;
//     bool write = false;
//     while (read(0, &buff, 1) == 1) {
//         switch (buff) {
//             case 'a':
//                 x--;
//                 break;
//             case 'd':
//                 x++;
//                 break;
//             case 'w':
//                 y--;
//                 break;
//             case 's':
//                 y++;
//                 break;
//             case 'x':
//                 write = !write;
//                 break;
//             default:
//                 continue;
//         }
//         if (write)
//             game->board[y][x] = '0';
//     }
// }

// void print_map(t_game *game) {
//     for(int i = 0; i < game->row; i++) {
//         for(int j = 0; j < game->cols; j++) {
//             putchar(game->board[i][j]);
//         }
//         putchar('\n');
//     }
// }

// int count_neigbour(t_game *game, int row, int col) {
//     int count = 0;
//     for (int i = -1; i < 2; i++) {
//         for (int j = -1; j < 2; j++) {
//             int r2 = row + i;
//             int c2 = col + j;
//             if (i == 0 && j == 0)
//                 ;
//             else if (game->board[r2][c2] == '0')
//                 count++;
//         }
//     }
//     return count;
// }

// void solve(t_game *game) {
//     char **new_map;
//     int neighbour = 0;
//     new_map = malloc(game->row * sizeof(char *));
//     if (!)
//     for (int i = 0; i < game->row; i++) {
//         new_map[i] = malloc(game->cols * sizeof(char));
//     }
//     for (int i = 0; i < game->row; i++) {
//         for (int j = 0; j < game->cols; j++) {
//             neighbour = count_neigbour(game, i, j);
//             if (game->board[i][j] == '0') {
//                 if (neighbour == 2 | neighbour == 3)
//                     new_map[i][j] = '0';
//                 else
//                     new_map[i][j] = ' ';
//             }
//             else {
//                 if (neighbour == 2)
//                     new_map[i][j] = '0';
//                 else
//                     new_map[i][j] = ' ';

//             }
//         }
//     }
//     free_board(game);
//     game->board = new_map;
// }

// int main(int ac, char **av) {
//     if (ac != 4)
//         return 1;
//     t_game game;
//     if (!init(av, &game))
//         return false;
//     fill_board(&game);
//     for (int i = 0; i < game.iteration; i++) {
//         solve(&game);
//     }
//     print_map(&game);
//     free_board(&game);
// }