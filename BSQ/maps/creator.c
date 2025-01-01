/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:22:23 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/30 21:22:23 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	generate_map(char **argv, int lines, int width, FILE *file)
{
	int		i;
	int		j;

	fprintf(file, "%d%c%c%c\n", lines, argv[2][0], argv[3][0], argv[4][0]);
	srand(time(NULL));
	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < width)
		{
			if (rand() % 4 == 0)
				fputc(argv[3][0], file);
			else
				fputc(argv[2][0], file);
		}
		fputc('\n', file);
	}
	fclose(file);
}

int	main(int argc, char **argv)
{
	int		lines;
	int		width;
	FILE	*file;

	if (argc != 6)
	{
		printf("Syntax error: %s ", argv[0]);
		printf("<filas> <vacío> <obstáculo> <lleno> <columnas>\n");
		exit(EXIT_FAILURE);
	}
	lines = atoi(argv[1]);
	width = atoi(argv[5]);
	if (lines <= 0 || width <= 0)
	{
		printf("Error en argumentos\n");
		exit(EXIT_FAILURE);
	}
	file = fopen("test", "w");
	if (!file)
	{
		perror("Error al abrir el archivo");
		exit(EXIT_FAILURE);
	}
	generate_map(argv, lines, width, file);
	return (0);
}
