/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** my_putnbr_base
*/

#include <stdlib.h>

int len(char *str)
{
    int cnt = 0;

    while (str[cnt] != '\0')
        cnt+=1;
    return (cnt);
}

char *my_revstr(char *str)
{
    int leng = len(str);
    char save_str[leng];
    int j = 0;
    int i = 0;

    while (str[i] != '\0') {
        save_str[i] = str[i];
        i = i + 1;
    }
    i = i - 1;
    while (i >= 0) {
        str[j] = save_str[i];
        j = j + 1;
        i = i - 1;
    }
    str[j] = '\0';
    return (str);
}

int lent_rslt(unsigned long long nbr, unsigned long long base)
{
    int count = 0;

    while (nbr > base) {
        nbr = nbr / base;
        count = count + 1;
    }
    count = count + 1;
    return (count);
}

char *nbr_base_to_str(unsigned long long nbr, char const *base, int i)
{
    unsigned long long step1 = nbr;
    unsigned int base_len = len((char *)base);
    unsigned long long disp;
    char *rslt = (char *)malloc(sizeof(char) * (lent_rslt(nbr, base_len) + 2));

    disp = nbr % base_len;
    rslt[i] = base[disp];
    while (step1 >= base_len) {
        i = i + 1;
        step1 = step1 / base_len;
        disp = step1 % base_len;
        rslt[i] = base[disp];
    }
    rslt[i + 1] = '\0';
    rslt = my_revstr(rslt);
    return (rslt);
}