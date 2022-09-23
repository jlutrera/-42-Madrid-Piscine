#include "bsq.h"

void	ft_print_solution(char **basemap, int data[5], int max[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < data[3])
	{
		j = 0;
		while (j < data[4])
		{
			if ((j >= max[0]) && (j < max[0] + max[2])
				&& (i >= max[1] && (i < max[1] + max[2])))
				write(1, &data[1], 1);
			else
				write(1, &basemap[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_row_square(char **basemap, int data[5], int temp[3])
{
	int	x;
	int	y;
	int	ok;
	int	ok_row;

	ok = 1;
	ok_row = 1;
	y = 0;
	while (y < temp[2] && ok && (temp[1] + y) < data[3])
	{
		x = 0;
		while (x < temp[2] && ok_row && (temp[0] + x) < data[4])
		{
			ok_row = (basemap[temp[1] + y][temp[0] + x] == data[0]);
			x++;
		}
		ok *= ok_row;
		y++;
	}
	if (ok)
		return (0);
	return (-1);
}

void	ft_savemax(int *max, int *temp, int data[5])
{
	max[0] = temp[0];
	max[1] = temp[1];
	max[2] = temp[2];
	temp[0] = data[4];
	temp[1] = data[3];
}

int	ft_squares(char **basemap, int lines, char *items, int width)
{
	int	temp[3];
	int	max[3];

	temp[2] = 1;
	while (temp[2] <= data[3])
	{
		temp[1] = 0;
		while (temp[1] <= (data[3] - temp[2]))
		{
			temp[0] = 0;
			while (temp[0] <= (data[4] - temp[2]))
			{
				if (ft_row_square(basemap, data, temp) == 0)
					ft_savemax(max, temp, data);
				temp[0]++;
			}
			temp[1]++;
		}
		temp[2]++;
	}
	ft_print_solution(basemap, data, max);
	return (0);
