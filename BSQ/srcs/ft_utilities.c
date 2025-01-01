/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:22:24 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/08 20:22:24 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_printf(char *str)
{
	int	n;

	n = -1;
	while (str[++n] != '\0')
		write(STDOUT_FILENO, &str[n], 1);
	return (n);
}

void	ft_freemaps(char **amap)
{
	int	i;

	if (amap)
	{
		i = -1;
		while (amap[++i])
			free(amap[i]);
		free(amap);
	}
}

int	ft_addchartostr(char **src, char *c, size_t *bytes_read, int fd)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(*src);
	dest = (char *)malloc((len + 2) * sizeof(char));
	if (!dest)
		return (0);
	i = -1;
	while ((*src)[++i])
		dest[i] = (*src)[i];
	dest[i] = *c;
	dest[i + 1] = '\0';
	*bytes_read = read(fd, c, 1);
	free(*src);
	*src = dest;
	return (0);
}

void	free_dp(int **dp, int lines)
{
	int	i;

	if (dp)
	{
		i = -1;
		while (++i < lines && dp[i])
			free(dp[i]);
		free(dp);
	}
}

void	ft_copymap(char **map, char **resultmap, int lines)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lines)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			resultmap[i][j] = map[i][j];
			j++;
		}
		resultmap[i][j] = '\0';
	}
}
