#include <stdlib.h>
#include <unistd.h>

void ft_print_solution(char **square, int size)
{
    int i;
    int j;

    i = -1;
    while (++i < size)
    {
        j = -1;
        while (++j < size)
        {
            write(1, &square[i][j], 1);
            write(1, " ", 1);
        }
        write(1, "\n", 1);         
    }
    write(1, "\n", 1); 
}

int ft_check_order(char **square, int c, int size)
{
    int i;
    int j;

    i = c;
    while (i > 0)
    {
        j = 0;
        while (++j < size)
           if (square[c][j] == square[i - 1][j])
            return (-1);
        --i;
     }
    if (c < size - 1)
        return (0);
    ft_print_solution(square, size);
    return (1);
}

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

void permuta(char **square, int c, int size)
{
    int i;
    int *x;
    int good;

    x = malloc(size * sizeof(int));
    if (x)
    {
        i = initialitation(x, size);
        ++c;
        good = ft_check_order(square, c, size);
        if (good == 0) 
            permuta(square, c, size);
        while (i < size && good != 1)
            if (x[i] < i)
            {
                i = ft_swap(square[c], i, x);
                good = ft_check_order(square, c, size);
                if ( good == 0)
                    permuta(square, c, size);
            }     
            else
                x[i++] = 1;
        free(x);
    }
}

int ft_fill(char **square, int size)
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
    permuta(square, 0, size);
}

int main(void)
{
    char **square;
    int i;
    int size = 9;

    square = malloc(size * sizeof(char **));
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
    free (square);
    return (0);
}