#include "libft.h"
#include <stdlib.h>


int get_un_size(unsigned int n)
{
    int counter;

    counter = 0;
    if (n == 0)
        return (1);
    while (n)
    {
        n /= 10;
        counter++;
    }
    return (counter);
}

char *ft_utoa(unsigned int n)
{
    int nbr_size;
    char *result;

    nbr_size = 0;
    nbr_size += get_un_size(n);
    result = (char*)malloc((nbr_size + 1) * sizeof(char));
    result[nbr_size--] = '\0';
    while (nbr_size >= 0)
    {
        result[nbr_size--] = n % 10 + 48;
        n /= 10; 
    }
    return (result);
}

