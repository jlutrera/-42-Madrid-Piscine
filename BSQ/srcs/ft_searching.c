#include "bsq.h"

void	ft_read_map(int file, char **basemap, int lines, int width)
{
	char	c;
	int		i;
	int		j;

	read(file, &c, 1);
	i = -1;
	while (++i < lines)
	{
		basemap[i] = malloc ((width + 1) * sizeof(char *));
		j = 0;
		read(file, &c, 1);
		while (c != '\n')
		{
			basemap[i][j] = c;
			j++;
			read(file, &c, 1);
		}
		basemap[j] = '\0';
	}
}

int	ft_searching(char *filename, int lines, char *items, int width)
{
	char	**basemap;
	int		file;
	char	c;

	file = open(filename, O_RDONLY);
	if (!file)
		return(-1);
	read(file, &c, 1);
	while (c != '\0')
		read(file, &c, 1);
	basemap = malloc (lines * sizeof(char **));
	if (!basemap)
		return(-1);
	ft_read_map(file, basemap, lines, width);
	close(file);
	ft_squares(basemap, lines, items, width);
	free(basemap);
	return (0);
}