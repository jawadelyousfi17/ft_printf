#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void printd(char *str, ...);

int main()
{
    printd("dcsd", 9, 'c', "Hello", 8);
    return 0;
}

void printd(char *str, ...)
{
    va_list ptr;

    int n = strlen(str);

    va_start(ptr, str);
    int i = 0;
    while (i < n)
    {
        if (str[i] == 'd')
        {
            int nbr = va_arg(ptr, int);
            printf("%d ", nbr);
        }
        else if (str[i] == 'c')
        {
            char ch = va_arg(ptr, int);
            printf("%c ", ch);
        }
        else if (str[i] == 's')
        {
            char *ch = va_arg(ptr, char *);
            printf("%s ", ch);
        }

        i++;
    }

    va_end(ptr);
}