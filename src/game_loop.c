/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_loop
*/

#include <curses.h>
#include "tetris.h"
#include "my.h"

char **move_left(char **board, size_tetri_t const pos, size_tetri_t const size);

static void display_map(game_t game)
{
    if (game.size_w.y > game.size_b.y && game.size_w.x > game.size_b.y)
        for (unsigned int i = 0; game.board[i] != NULL; i++)
            mvprintw(game.size_w.x / 2 - (game.size_b.y / 2) + i,
            (game.size_w.y - my_strlen(game.board[i])) / 2,
            "%s\n", game.board[i]);
    else
        mvprintw(game.size_w.x / 2, (game.size_w.y - my_strlen(
            "the screen is too small to display the game"))/2,
            "%s\n", "the screen is too small to display the game");
}

int game_loop(game_t game, touch_t touch, list_t *list)
{
    load_tetri(&game, list);
    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        wclear(stdscr);
        curs_set(0);
        getmaxyx(stdscr, game.size_w.x, game.size_w.y);
        display_map(game);
        usleep(1000);
        refresh();
        int get = getch();
        if (get == 't')
            break;
        if (get == 'q')
            game.board = move_left(game.board, game.tetri.pos, game.tetri.size);
    }
    endwin();
    return (0);
}