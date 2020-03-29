/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_loop
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static void manage_window(game_t *game)
{
    int y = 0;
    int x = 0;

    wclear(stdscr);
    wclear(game->windows[BOARD]);
    wclear(game->windows[TETRIMINO]);
    getmaxyx(stdscr, x, y);
    wmove(game->windows[BOARD], y/2-game->size_b.y/2, x/2-game->size_b.x/2);
    wborder(game->windows[BOARD], '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(game->windows[BOARD]);
    wrefresh(game->windows[TETRIMINO]);
    refresh();
}

int game_loop(game_t game, touch_t touch, list_t *list)
{
<<<<<<< HEAD
    int len = len_list(list);

    if (len == 0)
        return 84;
    game.tetri[0] = loading_tetrimino(game, list, len);
    game.tetri[1] = loading_tetrimino(game, list, len);
=======
    game.tetri[0] = loading_tetrimino(game, list, game.len_list);
    game.tetri[1] = loading_tetrimino(game, list, game.len_list);
>>>>>>> master
    init_window(&game);
    while (1) {
        manage_window(&game);
        display_tetri_game(game);
        manage_game(&game, list);
        display_tetri_game(game);
        if (manage_keys(&game, &touch))
            break;
    }
    endwin();
    return (0);
}
