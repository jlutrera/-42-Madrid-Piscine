//Permutaciones de N elementos
//ALGORITMO DE HEAP  (B.R. Heap - 1963)

#include <stdio.h>
#include <stdlib.h>

int ft_swap(char *cadena, int i, int *c)
{
    char aux;
    int j;

    if (i % 2 == 0)
        j = 0;
    else
        j = c[i];
    aux = cadena[i];
    cadena[i] = cadena[j];
    cadena[j] = aux;
    printf("%s\n",cadena);
    c[i] += 1;
    return (0);
}

void permuta(char *cadena, int *c, int size)
{
    int i;

    i = 0;
    while (i < size)
        if (c[i] < i)
            i = ft_swap(cadena, i, c);
        else
            c[i++] = 0;
}

void permutaciones(char *cadena, int size)
{
    int i;
    int *c;

    c = malloc(size * sizeof(int));
    i = -1;
    while (++i < size)
        c[i] = 0;
    printf("%s\n",cadena);
    permuta(cadena, c, size);
    free (c);
}

int main(void)
{
    char texto[] = "1234";
    permutaciones(texto, 4);
    return (0);
}