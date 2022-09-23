#include <stdlib.h>

int ft_permuta(char *sol, char **square, int c, int size);
/***********************************************************************/
/* Rellena el cuadrado latino con los números que faltan en cada fila  */
/***********************************************************************/
void ft_fill(char **square, int size)
{
    int i;
    int j;
    int k;

    k = 0;
    while (++k < size)
    {
        i = -1;
        j = 0;
        while (++i <size)
            if (i != k)
                square[k][++j] = i + '1';
        square[k][++j] = '\0';
    }
}
/*************************************************************/
/* Creamos el esqueleto de los cuadrados latinos reducidos:  */
/*  Primera file : 1 2 3 4 5 ... n                           */
/*  Primera columna : 1 2 3 4 5 ... n                        */
/*  Las demás filas son permutaciones de los  que faltan     */
/*************************************************************/
int ft_base_square(char *sol, int size)
{
    int i;
    char **square;
    int end;

    square = malloc (size * sizeof(char **));
    if (!square)
        return (-1);
    i = -1;
    while (++i < size)
    {
        square[i] = malloc ((size + 1) * sizeof(char *));
        square[i][0] = i + '1';
        square[0][i] = i + '1';
    } 
    ft_fill(square, size);
    end = ft_permuta(sol, square, 0, size);
    free(square);
    return (end);
}