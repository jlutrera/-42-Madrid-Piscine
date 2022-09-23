/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:03:13 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/10 11:30:14 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(int r, int x);

void	rush04(int x, int y)
{
	int		count_rows;
	char	*error;

	error = "¡ ERROR !  Valores no permitidos";
	count_rows = 1;
	if (x > 0 && y > 0)
	{
		ft_putchar(0, x);
		if (y > 1)
		{
			while (count_rows <= (y - 2))
			{
				ft_putchar(1, x);
				count_rows++;
			}
			ft_putchar(2, x);
		}
	}
	else
		write(1, error, 32);
}
