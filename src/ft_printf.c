#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define CHARSET "cspdiuxX"

void ft_printf(const char *source, ...);
int is_charset(char c, char *charset);
void ft_print_if(va_list *dest, char c);

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

void ft_printf(const char *source, ...)
{
    va_list ptr;
    va_start(ptr, source);
    while (*source)
    {
        if (*source == '%' && *(source + 1))
        {
            source++;
            if (is_charset(*source, CHARSET))
                ft_print_if(&ptr, *source);
            else
            {
                source--;
                printf("%c", *source);
            }
        }
        else
            printf("%c", *source);
        source++;
    }
    va_end(ptr);
}

void ft_print_if(va_list *dest, char c)
{
    if (c == 'd')
    {
        printf("%d", va_arg(*dest, int));
    }
    else if (c == 'c')
    {
        printf("%c", va_arg(*dest, int));
    }
    else if (c == 's')
    {
        printf("%s", va_arg(*dest, char *));
    }
    else if (c == 'i')
    {
        printf("%i", va_arg(*dest, int));
    }
    else if (c == 'p')
    {
        printf("%p", va_arg(*dest, void *));
    }
    else if (c == 'x')
    {
        printf("%x", va_arg(*dest, int));
    }
}