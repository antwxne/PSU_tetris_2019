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
    wclear(game->windows[BOARD]);
    wborder(game->windows[BOARD], '|', '|', '-', '-', '+', '+', '+', '+');
    wborder(game->windows[NEXT], '|', '|', '-', '-', '/', 'a', 's', '/');
    wborder(game->windows[INFO], '|', '|', '-', '-', '/', 'd', 'f', '/');
    for (int i = 0; i < 4; i++) {
        touchwin(game->windows[i]);
        wrefresh(game->windows[i]);
    }
    refresh();
}

int game_loop(game_t game, touch_t touch, list_t *list)
{
    game.tetri[0] = loading_tetrimino(game, list, game.len_list);
    game.tetri[1] = loading_tetrimino(game, list, game.len_list);
    init_window(&game);
    manage_window(&game);
    while (!game.loose) {
        manage_window(&game);
        manage_game(&game, list);
        display_tetri_game(game);
        if (manage_keys(&game, &touch))
            break;
        
    }
    endwin();
    my_putstr("You loose\n");
    return (0);
}
