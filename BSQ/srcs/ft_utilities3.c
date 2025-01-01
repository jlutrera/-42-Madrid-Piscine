/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:13:15 by jutrera-          #+#    #+#             */
/*   Updated: 2025/01/02 00:13:15 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	there_are_errors(int error, int fd, char **map)
{
	if (error == -2)
	{
		ft_freemaps(map);
		close(fd);
		ft_printf("memory allocation error\n");
		return (1);
	}
	if (error == -1)
	{
		ft_freemaps(map);
		close(fd);
		ft_printf("map error\n");
		return (1);
	}
	if (error == -3)
	{
		ft_printf("file error\n");
		return (1);
	}
	close(fd);
	return (0);
}
