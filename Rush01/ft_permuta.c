#include <stdlib.h>

int ft_check_solution(char *sol, char **square, int size);
int ft_columns(char *sol, char **square, int size);

/**************************************************************************/
/* Comprueba que la permutación es correcta para crear el cuadrado latino */
/* Y, si el cuadrado está completo, comprueba si es solución              */
/* En caso de que no fuera solución, permuta sus columnas                 */
/**************************************************************************/
int ft_check_order(char *sol, char **square, int c, int size)
{
    int i;
    int j;
    int end;

    i = c;
    while (i > 0)
    {
        j = 0;
        while (++j < size)
           if (square[c][j] == square[i - 1][j])
            return (-1);
        --i;
     }
    if (c == size - 1)
    {
        end =  ft_check_solution(sol, square, size);
        if (end == -1)
            end = ft_columns(sol, square, size);
        return (end); 
    }    
    return (1);
}
/**************************************************************************************/
/* Intercambiamos valores de cada fila para ir rellenando el cuadrado latino reducido */
/**************************************************************************************/
int ft_swap(char *cadena, int i, int *x)
{
    char aux;
    int j;

    if (i % 2 != 0)
        j = 1;
    else
        j = x[i];
    aux = cadena[i];
    cadena[i] = cadena[j];
    cadena[j] = aux;
    x[i] += 1;
    return (1);
}

int initialitation(int *x, int size)
{
    int i;

    i = -1;
    while (++i < size)
        x[i] = 1;
    return (1);
}
/******************************************************************/
/* Se comprueba si es correcta cada permutación                   */
/* La permutación se realiza utilizando el ALGORITMO DE HEAP      */
/* Permutamos cada fila hasta llegar al final, recursivamente     */
/* Cuando tenemos el cuadrado reducido comprobamos si es solución */
/* Si no lo es, permutamos filas                                  */
/* Si tampoco hay solución, permutamos columnas                   */
/******************************************************************/
int ft_permuta(char *sol, char **square, int c, int size)
{
    int i;
    int *x;
    int good;

    x = malloc(size * sizeof(int));
    if (!x)
        return (-1);
    i = initialitation(x, size);
    ++c;
    good = ft_check_order(sol, square, c, size);
    if (c < size - 1) 
        good = ft_permuta(sol, square, c, size);
    while (i < size && good != 0)
        if (x[i] < i)
        {
            i = ft_swap(square[c], i, x);
            good = ft_check_order(sol, square, c, size);
            if ( c < size - 1)
                good = ft_permuta(sol, square, c, size);
        }     
        else
            x[i++] = 1;
    free(x);
    return (good);
}