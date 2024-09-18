#include "libft.h"

int get_Hexa_size(long int n)
{
    int counter;

    counter = 0;
    if (n == 0)
    {
        return (1);
    }
    while (n)
    {
        n /= 16;
        counter++;
    }
    return (counter);
}

char *ft_itohx(int n, char *charset)
{
    long int nbr;
    int nbr_size;
    int is_negative;
    char *result;

    is_negative = 0;
    nbr = n;
    nbr_size = 0;
    if (nbr < 0)
    {
        is_negative = 1;
        nbr = -nbr;
        nbr_size++;
    }
    nbr_size += get_Hexa_size(nbr);
    result = (char *)malloc((nbr_size + 1) * sizeof(char));
    result[nbr_size--] = '\0';
    while (nbr_size >= 0)
    {
        result[nbr_size--] = charset[(int)nbr % 16];
        nbr /= 16;
    }
    if (is_negative)
        result[0] = '-';
    return (result);
}
