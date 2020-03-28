/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_loop
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

static void manage_window(WINDOW **te, WINDOW **w_tetri, game_t game)
{
    int y = 0;
    int x = 0;

    wclear(stdscr);
    wclear(*w_tetri);
    wclear(*te);
    getmaxyx(stdscr, x, y);
    wmove(*w_tetri, y / 2 - game.size_b.y / 2, x / 2 - game.size_b.x / 2);
    wborder(*w_tetri, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(*w_tetri);
    wrefresh(*te);
}

static int len_list(list_t const *list)
{
    int len = 0;
    list_t *temp = list;

    for (; temp != NULL; temp = temp->next)
        len++;
    return (len);
}

int game_loop(game_t game, touch_t touch, list_t *list)
{
    WINDOW *board;
    WINDOW *tetrimino;
    int len = len_list(list);

    loading_tetrimino(&game, list, len);
    init_window(&tetrimino, &board, game);
    while (1) {
        manage_window(&tetrimino, &board, game);
        usleep(1000);
        display_tetri_game(board, tetrimino, game);
        // met ta fonction pour les touches ici a la place des if
        int get = wgetch(tetrimino);
        if (get == 't')
            break;
        if (get == 'q')
            game.tetri.pos = move_left(game.board, game.tetri.pos);
        if (get == 'd')
            game.tetri.pos = move_right(game.board, game.tetri.pos,
            game.tetri.size);
        if (get == 's')
            game.tetri.pos = move_down(game.board, game.size_b, game.tetri.pos,
            game.tetri.size);
    }
    endwin();
    return (0);
}