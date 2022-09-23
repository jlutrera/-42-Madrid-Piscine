#include "bsq.h"

int	ft_check_repeating(int file, char *s)
{
	int		i;
	char	c;

	i = -1;
	while (c != '\n' || ++i < 3)
	{
		s[i] = c;
		read(file, c, 1);
	}
	return (i == 2 && (s[0] != s[1] && s[1] != s[2] && s[0] != s[2]));
}

int	ft_check_first(int file)
{
	char	c;
	int		l;

	read(file, &c, 1);
	if (c > '0' && c < '9')
		l = c - 48;
	else
		l = -1;
	while (c > '0' && c < '9')
	{
		l *= 10 + c - 48;
		read(file, &c, 1);
	}
	return (l);
}

int	ft_check_lines(int file, int lines, char *s)
{
	char	c;
	int		dim[3];

	dim[0] = 0;  //guarda el ancho del mapa.  Todas las líneas deben tener el mismo ancho
	dim[1] = 0;  //Guarda el ancho del mapa, de la línea anterior
	dim[2] = 0;  //Guarda las líneas que hay en el mapa, de verdad
	read(file, &c, 1);
	while (c != EOF && c == s[0] && c == s[1])
	{
		dim[2]++;
		read(file, &c, 1);
		dim[0] = 0;
		while (c != '\n' && c == s[0] && c == s[1])
		{
			dim[0]++;
			read(file, &c, 1);
		}
		if (dim[1] != dim[0] && dim[2] > 1)
			return (-1);
		dim[1] = dim[0];
	}
	if (lines == dim[2])
		return (dim[1]);
	return(-1);
}

int ft_check_map(char *filename)
{
	int 	lines;
	int 	file;
	char 	*items;
	int		width;

	file = open(filename, O_RDONLY);
	if (!file)
		return (-1);
	lines = ft_check_first(file);
	if (lines > 0)
	{
		items = malloc (3 * sizeof(char));
		if (ft_check_repeating(file, items) == 0)
		{
			width = ft_check_lines(file, lines, items) ;
			if (width > 0)
			{
				close(file);
				ft_searching(filename, lines, items, width);
				free(items);
				return (0);
			}
		}	
		free(items);
	}
	close(file);
	return (-1);
}
