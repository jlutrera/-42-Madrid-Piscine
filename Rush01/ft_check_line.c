/********************************************************************/
/* Esta función calcula la soiución de una fila/columna del cuadrado*/
/********************************************************************/

int	ft_check_line(char sol, char *m, int size)
{
	int		i;
	int		j;
	char	n;

	n = '1';
	i = 0;
	j = 1;
	while (j <= (size - 1))
	{
		if (m[i] < m[j])
		{
			n++;
			i = j;
			j = i + 1;
		}
		else
			j++;
	}
	if (n == sol)
		return (0);
	return (-1);
}
