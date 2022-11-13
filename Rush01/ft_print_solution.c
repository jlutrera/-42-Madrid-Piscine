#include <unistd.h>

/*****************************************************/
/* Esta función imprime la solución que se encuentre */
/*****************************************************/
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
}