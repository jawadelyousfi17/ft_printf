#include "libft.h"


#define CHARSET "cspdiuxX%"


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

int ft_printf(const char *source, ...)
{
    va_list ptr;
    va_start(ptr, source);
    int reselt;
    reselt = 0;
    while (*source)
    {
        if (*source == '%' && *(source + 1))
        {
            source++;
            if (is_charset(*source, CHARSET))
                reselt += ft_print_if(&ptr, *source);
            else
                reselt += ft_putchar(*source);
        }
        else
            reselt += ft_putchar(*source);
        source++;
    }
    va_end(ptr);
    return reselt;
}

int ft_print_if(va_list *dest, char c)
{
    if (c == 'd')
        return ft_putnbr(va_arg(*dest, int));
    else if (c == 'c')
        return ft_putchar(va_arg(*dest, int));
    else if (c == 's')
        return ft_putstr(va_arg(*dest, char *));
    else if (c == 'i')
        return ft_putnbr(va_arg(*dest, int));
    else if (c == '%')
        return ft_putchar(c);
    else if (c == 'x')
        return ft_printhexa(va_arg(*dest, int));
    else if (c == 'X')
        return ft_printhexaUp(va_arg(*dest, int));
    else if (c == 'u')
        return ft_putunsigned(va_arg(*dest, int));
    return 0;
}