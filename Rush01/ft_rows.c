#include <stdlib.h>

int ft_check_solution(char *sol, char **square, int size);
char **ft_tablecpy(char **square, int size);

/****************************************/
/* Intercambia los valores de dos filas */
/****************************************/
int ft_swap_rows(char **aux, int i, int *c, int size)
{
    char swap;
    int k;
    int j;

    if (i % 2 != 0)
        j = 1;
    else
        j = c[i];
    k = -1;
    while (++k < size)
    {
        swap = aux[i][k];
        aux[i][k] = aux[j][k];
        aux[j][k] = swap;
    }
    c[i] += 1;
    return (1);
}

/**********************************************************************/
/* Usando el ALGORITMO DE HEAP permutamos las filas (menos la primera */
/* comprobamos si es solución el nuevo cuadrado generado              */
/**********************************************************************/
int ft_permutation_row(char *sol, char **aux, int *c, int size)
{
    int i;
    int end;

    end = -1;
    i = 1;
    while (i < size && end == -1)
    {
        if (c[i] < i)
        {
            i = ft_swap_rows(aux, i, c, size);
            end = ft_check_solution(sol, aux, size);
        }
        else
            c[i++] = 1;
    }
    return (end);
}

/***********************************************************************/
/* El cuadrado reducido original se copia para generar todos los demás */
/* Hacemos las permutaciones de las filas (menos la primera)           */
/***********************************************************************/
int ft_rows(char *sol, char **square, int size)
{
    int i;
    int end;
    char **aux;
    int *c;

    aux = malloc (size * (size + 1) * sizeof(char));
    if (!aux)
        return (-1);
    aux = ft_tablecpy(square, size);
    c = malloc(size * sizeof(int));
    if (!c)
        return (-1);
    i = -1;
    while (++i < size)
        c[i] = 1;
    end = ft_permutation_row(sol, aux, c, size);
    free(aux);
    free (c);
    return (end);
}