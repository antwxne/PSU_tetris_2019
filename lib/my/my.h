/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void my_swap(int *a, int *b);
int my_getnbr(char const *str);
int my_isneg(int n);
void my_putchar(char c);
int my_put_nbr(int nb);
void my_putstr(char const *str);
char *my_revstr(char *str);
int counter(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2);
char *my_strncpy(char *dest, char const *src, int n);
void my_printf(char *str, ...);
void my_free_arr(char **arr, int start);
int my_btoi(char *bin);
char *clean_bin(char *bin);
char *my_str_c_copy(char const *str, char c);
char **epur_shape(char **shape);

#endif /* !MY_H_ */
