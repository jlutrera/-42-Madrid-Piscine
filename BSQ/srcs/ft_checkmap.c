/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:39:35 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/09 23:55:55 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	ft_checkfirstline(int fd, char **chars)
{
	char	c;
	int		l;
	int		i;

	read(fd, &c, 1);
	l = 0;
	while (c >= '0' && c <= '9')
	{
		l = l * 10 + c - '0';
		read(fd, &c, 1);
	}
	if (l == 0)
		return -2;
	i = 0;
	while (c != '\n' && i < 3)
	{
		(*chars)[i] = c;
		read(fd, &c, 1);
		i++;
	}
	if (i == 3 && ((*chars)[0] != (*chars)[1] && (*chars)[1] != (*chars)[2] && (*chars)[0] != (*chars)[2]))
		return l;
	return -2;
}

static int	something_is_wrong(char c, int *width, char *line, char *s, size_t bytes_read)
{
	int	len;

	if (c != s[0] && c != s[1] && c != '\n' && bytes_read > 0)
		return 1;
	len = ft_strlen(line);
	if (*width == 0)
		*width = len;
	if (*width != len)
		return 1;
	return 0;
}
static int	ft_checkmaplines(int fd, int lines, char *s, char **map)
{
	char	c;
	int		len;
	int		width;
	size_t	bytes_read;
	
	len = 0;
	width = 0;
	while (1)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read == 0 || (c != s[0] && c != s[1]))
			break;
		map[len] = (char *)malloc(1 * sizeof(char));
		if (!map[len])
			return -2;
		map[len][0] = '\0';
		while (c != '\n' && bytes_read > 0 && (c == s[0] || c == s[1]))
		{
			map[len] = ft_addchartostr(map[len], c);
			if (!map[len])
				return -2;
			bytes_read = read(fd, &c, 1);
		}
		if (something_is_wrong(c, &width, map[len], s, bytes_read))
			break;
		len++;
		if (bytes_read == 0)
			break;
	}
	map[len] = '\0';
	if (len != lines)
		return -1;
	return 0;
}

static int there_are_errors(int error, int fd, char **map)
{
	if (error == -2)
	{
		ft_freemaps(map);
		close(fd);
		ft_printf("memory allocation error\n");
		return 1;
	}
	if (error == -1)
	{
		ft_freemaps(map);
		close(fd);
		ft_printf("map error\n");
		return 1;
	}
	if (error == -3)
	{
		ft_printf("file error\n");
		return 1;
	}
	close(fd);
	return 0;
}

char **ft_checkmap(char *filename, int *lines, char **chars)
{
	int 	fd;
	int 	error;
	char	**map;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		error = -3;
	else
		error = ft_checkfirstline(fd, chars);
	if (error > 0)
	{
		*lines = error;
		map = (char **)malloc ((*lines + 1) * sizeof(char *));
		if (!map)
			error = -2;
		else
			error = ft_checkmaplines(fd, *lines, *chars, map);
	}
	if (there_are_errors(error, fd, map))
		return NULL;
	else
		return map;
}
