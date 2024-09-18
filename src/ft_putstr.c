#include "libft.h"




int ft_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int ft_putstr(const char *s)
{
    int size;

    size = (int)ft_strlen(s);
    while (*s)
    {
        ft_putchar(*s);
        s++;
    }
    return (size);
}

int ft_putnbr(int nbr)
{
    char *str;
    str = ft_itoa(nbr);
    return (ft_putstr(str));
}

int ft_printhexa(int nbr)
{
    return (ft_putstr(ft_itohx(nbr, "0123456789abcdef")));
}
int ft_printhexaUp(int nbr)
{
    return (ft_putstr(ft_itohx(nbr, "0123456789ABCDEF")));
}
int ft_putunsigned(unsigned int nb)
{
    return (ft_putstr(ft_utoa(nb)));
}