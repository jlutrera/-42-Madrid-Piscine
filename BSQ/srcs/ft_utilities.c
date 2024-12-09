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

int ft_printf(char *str)
{
	int	n;

	n = -1;
	while (str[++n] != '\0')
		write(STDOUT_FILENO, &str[n], 1);
	return n;
}

void ft_freemaps(char **amap)
{
	int i;

	if (amap)
	{
		i = -1;
		while (amap[++i])
			free(amap[i]);
		free(amap);
	}
}

char *ft_addchartostr(char *src, char c)
{
	char	*dest;
	int		len;
	int		i;

	len = ft_strlen(src);
	dest = (char *)malloc((len + 2) * sizeof(char));
	if (!dest)
		return NULL;
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = c;
	dest[i + 1] = '\0';
	free(src);
	return dest;
}
