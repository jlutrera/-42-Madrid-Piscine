#include <stdlib.h>

int ft_check_solution(char *sol, char **square, int size);
int ft_rows(char *sol, char **square, int size);
char **ft_tablecpy(char **square, int size);

/*******************************************/
/* Intercambia los valores de dos columnas */
/*******************************************/
int ft_swap_cols(char **square, int i, int *c, int size)
{
    char swap;
    int k;
    int j;

    if (i % 2 == 0)
        j = 0;
    else
        j = c[i];
    k = -1;
    while (++k < size)
    {
        swap = square[k][i];
        square[k][i] = square[k][j];
        square[k][j] = swap;
    }
    c[i] += 1;
    return (0);
}

/*********************************************************/
/* Usando el ALGORITMO DE HEAP permutamos las columnas y */
/* comprobamos si es solución el nuevo cuadrado generado */
/* si no lo es, permutamos las filas, menos la primera   */
/*********************************************************/
int ft_permutation_col(char *sol, char **square, int *c, int size)
{
    int i;
    int end;

    i = 0;
    end = ft_rows(sol, square, size);
    while (i < size && end == -1)
    {
        if (c[i] < i)
        {
            i = ft_swap_cols(square, i, c, size);
            end = ft_check_solution(sol, square, size);
            if (end == -1)
                end = ft_rows(sol, square, size);
        }
        else
            c[i++] = 0;
    }
    return (end);
}

/***********************************************************************/
/* El cuadrado reducido original se copia para generar todos los demás */
/* Hacemos las permutaciones de las columnas                           */
/***********************************************************************/
int ft_columns(char *sol, char **square, int size)
{
    int i;
    int *c;
    int end;
    char **aux;

    aux = malloc (size * (size + 1) * sizeof(char));
    if (!aux)
        return (-1);
    aux = ft_tablecpy(square, size);
    c = malloc(size * sizeof(int));
    if (!c)
        return (-1);
    i = -1;
    while (++i < size)
        c[i] = 0;
    end = ft_permutation_col(sol, aux, c, size);
    free (aux);
    free (c);
    return (end);
}