#include <stdlib.h>

/********************************************/
/* Esta función hace una copia del cuadrado */
/********************************************/
char **ft_tablecpy(char **square, int size)
{
    int i;
    int j;
    char **p;

    p = malloc (size * sizeof(char **));
    if (p)
    {
        i = -1;
        while (++i < size)
        {
            j = -1;
            p[i] = malloc((size + 1) * sizeof(char *));
            while (++j < size)
                p[i][j] = square[i][j];
            p[i][j] = '\0';
        }
        return (p);
    }
    return (NULL);
}
