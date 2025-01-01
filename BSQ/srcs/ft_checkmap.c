/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:39:35 by jutrera-          #+#    #+#             */
/*   Updated: 2025/01/02 00:14:28 by jutrera-         ###   ########.fr       */
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
		return (-2);
	i = 0;
	while (c != '\n' && i < 3)
	{
		(*chars)[i] = c;
		read(fd, &c, 1);
		i++;
	}
	(*chars)[i] = '\0';
	if (i == 3 && ((*chars)[0] != (*chars)[1] && (*chars)[1] != (*chars)[2] &&
			(*chars)[0] != (*chars)[2]))
		return (l);
	return (-2);
}

static int	is_not_valid(char c, char *s, size_t bytes_read)
{
	if (c != s[0] && c != s[1] && c != '\n' && bytes_read > 0)
		return (1);
	return (0);
}

static int	something_is_wrong(int *width, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (*width == 0)
		*width = len;
	if (*width != len)
		return (1);
	return (0);
}

static int	ft_checkmaplines(int fd, int lines, char *s, char **map)
{
	char	c;
	int		d[2];
	size_t	bytes_read;

	d[0] = 0;
	d[1] = 0;
	while (1)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read <= 0 || (c != s[0] && c != s[1]))
			break ;
		map[d[0]] = (char *)calloc(1, sizeof(char));
		if (!map[d[0]])
			return (-2);
		while (c != '\n' && bytes_read > 0 && (c == s[0] || c == s[1]))
			if (ft_addchartostr(&map[d[0]], &c, &bytes_read, fd))
				return (-2);
		if (is_not_valid(c, s, bytes_read)
			|| something_is_wrong(&d[1], map[++d[0] - 1]))
			return (map[d[0]] = '\0', -1);
		if (bytes_read <= 0)
			break ;
	}
	map[d[0]] = '\0';
	return (-1 * (d[0] != lines));
}

char	**ft_checkmap(char *filename, int *lines, char **chars)
{
	int		fd;
	int		error;
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
		return (NULL);
	else
		return (map);
}
