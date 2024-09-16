#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHARSET "cspdiuxX"

int is_charset(char c, char *charset)
{
    while (*charset)
    {
        if (c == *charset)
            return (1);
        charset++;
    }
    return (0);
}

int get_n_args(const char *s)
{
    int index;
    int n_args;

    n_args = 0;
    index = 0;
    if (!s)
        return (0);
    while (*s)
    {
        if (*s == '%' && *(s + 1))
        {
            s++;
            if (is_charset(*s, CHARSET))
                n_args++;
        }
        s++;
    }
    return (n_args);
}

char *format_specifiers(const char *s, int size)
{
    char *charset;
    char *result;
    int i;

    i = 0;
    result = malloc(sizeof(char) * (size + 1));
    charset = "cspdiuxX";
    if (!s)
        return (0);
    while (*s)
    {
        if (*s == '%' && *(s + 1))
        {
            s++;
            if (is_charset(*s, charset))
            {
                result[i++] = *s;
            }
        }
        s++;
    }
    result[i] = 0;
    return (result);
}

// int main()
// {
//     char *test1 = NULL;
//     int n_args1 = get_n_args(test1);
//     printf("%d \n",n_args1);
//     return 0;
// }