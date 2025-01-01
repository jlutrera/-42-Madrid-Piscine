/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:39:07 by jutrera-          #+#    #+#             */
/*   Updated: 2025/01/01 23:26:52 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	printhorizontal(int k, char **map)
{
	int	i;
	int	width;

	if (k == 1)
		ft_printf("┌─");
	else
		ft_printf("└─");
	i = -1;
	width = ft_strlen(map[0]);
	while (++i < width)
		ft_printf("─");
	if (k == 1)
		ft_printf("─┐\n");
	else
		ft_printf("─┘\n");
}

static void	ft_printmap(int t, char *name, char **map)
{
	int	i;

	if (t == 1)
	{
		ft_printf("\nMap: ");
		ft_printf(YELLOW);
		ft_printf(name);
		ft_printf(RESET);
		ft_printf("\n");
	}
	else
		ft_printf(name);
	printhorizontal(1, map);
	i = -1;
	while (map[++i])
	{
		ft_printf("│ ");
		ft_printf(map[i]);
		ft_printf(" │\n");
	}
	printhorizontal(2, map);
}

static void	ft_process(char *filename)
{
	char	**basemap;
	char	**resultmap;
	char	*chars;
	int		lines;

	chars = (char *)malloc (4 * sizeof(char));
	if (!chars)
		ft_printf("memory allocation error\n");
	else
	{
		basemap = ft_checkmap(filename, &lines, &chars);
		if (basemap)
		{
			ft_printmap(1, filename, basemap);
			printf("chars: %s\n", chars);
			resultmap = find_largest(basemap, lines, chars);
			if (resultmap)
				ft_printmap(0, "Solution:\n", resultmap);
			else
				ft_printf("map error\n");
			ft_freemaps(basemap);
			ft_freemaps(resultmap);
		}
		free(chars);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	*filename;
	int		fd;

	i = 0;
	if (argc == 1)
	{
		fd = ft_createmap();
		if (fd == -1)
			return (1);
		ft_process("./maps/madrid42");
	}
	else
	{
		while (++i < argc)
		{
			filename = argv[i];
			ft_process(filename);
		}
	}
	return (0);
}
