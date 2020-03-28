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
}

static int len_list(list_t const *list)
{
    int len = 0;
    list_t const *temp = list;

    for (; temp != NULL; temp = temp->next)
        len++;
    return (len);
}

int game_loop(game_t game, touch_t touch, list_t *list)
{
    int len = len_list(list);

    loading_tetrimino(&game, list, len);
    init_window(&game);
    while (1) {
        manage_window(&game);
        display_tetri_game(game);
        // met ta fonction pour les touches ici a la place des if
        wtimeout(game.windows[TETRIMINO], 1000 - game.level * 10);
        int get = wgetch(game.windows[TETRIMINO]);
        if (get == 't')
            break;
        if (get == 'q')
            game.tetri.pos = move_left((char const **)game.board,
                game.tetri.pos);
        if (get == 'd')
            game.tetri.pos = move_right((char const **)game.board,
            game.tetri.pos, game.tetri.size);
        if (get == 's')
            game.tetri.pos = move_down((char const **)game.board, game.size_b,
            game.tetri.pos, game.tetri.size);
        if (get == -1)
            game.tetri.pos = move_down((char const **)game.board, game.size_b,
            game.tetri.pos, game.tetri.size);
        get = -1;
    }
    endwin();
    return (0);
}
