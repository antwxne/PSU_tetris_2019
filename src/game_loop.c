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
    wclear(stdscr);
    wclear(game->windows[BOARD]);
    wclear(game->windows[TETRIMINO]);
    wclear(game->windows[INFO]);
    wclear(game->windows[NEXT]);
    wborder(game->windows[INFO], '|', '|', '-', '-', '/', '\\', '\\', '/');
    wborder(game->windows[NEXT], '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(game->windows[BOARD], '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(game->windows[BOARD]);
    wrefresh(game->windows[TETRIMINO]);
    wrefresh(game->windows[INFO]);
    wrefresh(game->windows[NEXT]);
    refresh();
}

int game_loop(game_t game, touch_t touch, list_t *list)
{
    game.tetri[0] = loading_tetrimino(game, list, game.len_list);
    game.tetri[1] = loading_tetrimino(game, list, game.len_list);
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
