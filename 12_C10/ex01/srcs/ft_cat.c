/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:37:07 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/28 15:38:12 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_cat(char *file)
{
	int		r;
	int		f;
	char	a;

	f = open(file, 0);
	if (f == -1)
	{
		ft_display_custom_error(errno, file);
		return (-1);
	}
	r = read(f, &a, 1);
	while (r != -1 && r != 0)
	{
		write(1, &a, 1);
		r = read(f, &a, 1);
	}
	if (r == -1)
	{
		ft_display_custom_error(errno, file);
		return (0);
	}
	close(f);
	return (1);
}
