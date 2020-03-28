/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_loop
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

int block_tetri(WINDOW *w_tetri, tetrimino_t t);

void display_tetri(WINDOW *w_tetri, game_t game);

void loading_tetrimino(game_t *game, list_t const *list,
    int const len_list);

static void display_map(WINDOW *window, WINDOW *sub, game_t game)
{
    if (game.size_w.y > game.size_b.y && game.size_w.x > game.size_b.y) {
        for (unsigned int i = 0; game.board[i] != NULL; i++)
            mvwprintw(window, game.size_w.x / 2 - (game.size_b.y / 2) + i,
            (game.size_w.y - my_strlen(game.board[i])) / 2,
            "%s\n", game.board[i]);
            mvwprintw(sub, 0, 0, "%s\n", "pl");
    } else
        mvprintw(game.size_w.x / 2, (game.size_w.y - my_strlen(
            "the screen is too small to display the game"))/2,
            "%s\n", "the screen is too small to display the game");
}

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
        display_tetri(tetrimino, game);
        //block_tetri(w_tetri, game.tetri);
        int get = getch();
        if (get == 't')
            break;
    }
    endwin();
    return (0);
}