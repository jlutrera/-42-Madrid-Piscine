#include "bsq.h"
#include <stdio.h>

int	ft_parse(char buffer[100], int count)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < count && buffer[i] > '0' && buffer[i] < '9')
	{
		n = n * 10 + buffer[i] - 48;
		i++;
	}
	return (n);
}

char *ft_create_map(void)
{
	char	buffer[100];
	char	*filename;
	int		str[3];
	int		i;

	filename = "./Madrid42_map";
	str[0] = open(filename, O_RDONLY | O_CREAT);
	str[1] = read(1, buffer, 100);
	str[2] = ft_parse(buffer, str[1]);
	if (num > 0)
	{
		str[1] = write(str[0], buffer, str[1]);
		i = 0;
		while (i < str[2])
		{
			str[1] = read(1, buffer, 100);
			str[1] = write(str[0], buffer, str[1]);
			i++;
		}
	}
	close(str[0]);
	return (filename);
}
