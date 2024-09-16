#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#define CHARSET "cspdiuxX"

void ft_printf(const char *source, ...);
int get_n_args(const char *s);
char *format_specifiers(const char *s, int size);
int is_charset(char c, char *charset);

int main()
{
    ft_printf("Hello%s %d %c %i %%\n", " world", 5, 'c',45);
}

void ft_printf(const char *source, ...)
{
    va_list ptr;
    va_start(ptr, source);
    int n_args = get_n_args(source);
    int index = 0;
    // char *f_specifiers = format_specifiers(source, n_args);

    while (*source)
    {
        if (*source == '%' && *(source + 1))
        {
            source++;
            if (is_charset(*source, CHARSET))
            {
                if(*source == 'd')
                {
                    printf("%d",va_arg(ptr, int));
                } else if (*source == 'c')
                {
                     printf("%c",va_arg(ptr, int));
                } else if (*source == 's')
                {
                    printf("%s",va_arg(ptr, char*));
                } else if (*source == 'i') 
                {
                    printf("%i",va_arg(ptr, int));
                }
            } else {
                source--;
                printf("%c",*source);
            }
        } else 
            printf("%c", *source);
        source++;
    }
    va_end(ptr);
}
