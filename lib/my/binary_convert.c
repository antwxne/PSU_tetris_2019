/*
** EPITECH PROJECT, 2020
** navy
** File description:
** binary convert
*/

int my_strlen(char *str);

int my_btoi(char *bin)
{
    int len = my_strlen(bin);

    if (len == 4)
        return ((bin[3]-'0')*1+(bin[2]-'0')*2+
                (bin[1]-'0')*4+(bin[0]-'0')*8);
    if (len == 3)
        return ((bin[2]-'0')*1+(bin[1]-'0')*2+
                (bin[0]-'0')*4);
    if (len == 2)
        return ((bin[1]-'0')*1+(bin[0]-'0')*2);
    if (len == 1)
        return ((bin[0]-'0')*1);
}
