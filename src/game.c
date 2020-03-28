/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#include "tetris.h"
#include "my.h"

static size_tetri_t get_size_board(char *size)
{
    size_tetri_t board_size = {0, 0};
    char *temp;
    int i = 0;

    board_size.y = my_getnbr(size);
    for (; size[i] != '*'; i++);
    temp = &size[i];
    board_size.x = my_getnbr(temp);
    return (board_size);
}

static game_t init_game(touch_t touch)
{
    game_t game = {0};

    game.size_b = get_size_board(touch.touching[size]);
    game.score = 0;
    game.level = 0;
    game.board = create_board(game.size_b.x, game.size_b.y);
    return (game);
}

int game(touch_t touch, list_t *list)
{
    game_t game = init_game(touch);

    if (game.board == NULL)
        return (-1);
    return (game_loop(game, touch, list));
}