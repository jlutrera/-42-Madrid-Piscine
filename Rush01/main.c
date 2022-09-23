#include <stdlib.h>
#include <unistd.h> 

int ft_base_square(char *sol, int size);

void	ft_error(void)
{
	write(1, "Error\n", 6);
}
/********************************************************************************/
/* Comprobamos que hay un número correcto de dígitos y espacios (múltiplo de 8) */
/* determinamos el tamaño del cuadrado                                          */
/********************************************************************************/
int ft_check_size(char *s)
{
	int i;
	int size;

	i = 0;
	while (s[i])
		i++;
	if ((i + 1) % 8 != 0)
		return (-1);
	size = (i + 1) / 8;
	return (size);
}

/**********************************************************************/
/* Quitamos los espacios entre las cifras y devolvemos un string (*p) */
/**********************************************************************/
char *ft_cast(char *s, int size)
{
	int		i;
	char	*p;

	p = malloc(size * 4 + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] >= '1' && s[i] <= size + '0')
		{
			*p = s[i];
			++p;
		}
		else if (s[i] != 32)
			return (NULL);
	}
	*p = '\0';
	p = p - size * 4;
	return (p);
}

int	main(int argc, char **argv)
{
	int end;
	int size;

	end = -1;
	if (argc == 2)
	{
		size = ft_check_size(argv[1]);
		if (size != -1)
		{
			argv[1] = ft_cast(argv[1], size);
			if (argv[1] != NULL)
				end =  ft_base_square(argv[1], size);	
		}
	}
	if (end == -1)
		ft_error();
	return (0);
}
