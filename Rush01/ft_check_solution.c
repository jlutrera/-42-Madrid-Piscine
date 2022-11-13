#include <stdlib.h>

int ft_check_line(char sol, char *s, int size);
void ft_print_solution(char **square, int size);

/************************************/
/* Chequea las soluciones de arriba */
/************************************/
int ft_check_colup(char *sol, char **square, int size)
{
	int i;
	int j;
	char *s;
	int ok;

	s = malloc ((size + 1) * sizeof(*s));
	if (!s)
		return (-1);
	ok = 0;
	i = -1;
	while (++i < size && ok == 0) 
	{
		j = -1;
		while (++j < size)
			s[j] = square[j][i];
		ok = ft_check_line(sol[i], s, size);
	}
	free(s);
	return(ok);
}

/************************************/
/* Chequea las soluciones de abajo  */
/************************************/
int ft_check_coldown(char *sol, char **square, int size)
{
	int i;
	int j;
	char *s;
	int ok;

	s = malloc ((size + 1) * sizeof(*s));
	if (!s)
		return (-1);
	ok = 0;
	i = -1;
	while (++i < size  && ok == 0) 
	{
		j = -1;
		while (++j < size)
			s[j] = square[size - 1 - j][i];	
		ok = ft_check_line(sol[size + i], s, size);
	}
	free(s);
	return (ok);
}

/******************************************/
/* Chequea las soluciones de la izquierda */
/******************************************/
int ft_check_rowleft(char *sol, char **square, int size)
{
	int i;
	int j;
	char *s;
	int ok;

	s = malloc ((size + 1) * sizeof(*s));
	if (!s)
		return (-1);
	ok = 0;
	i = -1;
	while (++i < size  && ok == 0) 
	{
		j = -1;
		while (++j < size)
			s[j] = square[i][j];
		ok = ft_check_line(sol[2 * size + i], s, size);
	}
	free(s);
	return(ok);
}

/*****************************************/
/* Chequea las soluciones de la derecha  */
/*****************************************/
int ft_check_rowright(char *sol, char **square, int size)
{
	int i;
	int j;
	char *s;
	int ok;

	s = malloc ((size + 1) * sizeof(*s));
	if (!s)
		return (-1);
	ok = 0;
	i = -1;
	while (++i < size  && ok == 0) 
	{
		j = -1;
		while (++j < size)
			s[j] = square[i][size - 1 - j];
		ok = ft_check_line(sol[3 * size + i], s, size);
	}
	free(s);
	return(ok);
}

/***********************************************************************************/
/* Comprueba si nuestro cuadrado tiene las mismas soluciones que las que nos pasan */
/* En caso afirmativo lo muestra                                                   */
/***********************************************************************************/
int ft_check_solution(char *sol, char **square, int size)
{
	int ok;

	ok = ft_check_colup(sol, square, size)
		+ ft_check_coldown(sol, square, size)
		+ ft_check_rowleft(sol, square, size)
		+ ft_check_rowright(sol, square, size);
	if (ok == 0)
	{
        ft_print_solution(square, size);
		return (0);
	}
	return (-1);

}