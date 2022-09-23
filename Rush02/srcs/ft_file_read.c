/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 19:47:04 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/24 18:39:44 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

char	*addchar(char *str, char *buf)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i])
		i++;
	new = malloc (sizeof(char) * (i + 2));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (str[++i])
		new[i] = str[i];
	new[i] = buf[0];
	new[i + 1] = '\0';
	free(str);
	return (new);
}

int	gest_buf(int file, t_dict *begin)
{
	int		size;
	char	*str;
	char	buf[1];

	str = malloc(sizeof(char));
	str[0] = '\0';
	size = read(file, buf, 1);
	while (size != 0)
	{
		if (buf[0] != '\n')
			str = addchar(str, buf);
		else
		{
			if (parse_dict(begin, str) == 1)
			{
				free(str);
				str = malloc(sizeof(char));
				str[0] = '\0';
			}
			else if (ft_strlen(str) != 0)
				return (0);
		}
	}
	ft_list_sort(begin);
	return (1);
}

int	ft_file_read(char *filepath, t_dict *begin)
{
	int	file;
	int	size;

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		if (gest_buf(file, begin) == 0)
			return (-1);
		return (1);
	}
	else
		return (0);
}
