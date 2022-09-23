/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:03:13 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/10 11:29:19 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include <unistd.h>

void	ft_putchar(int r, int x)
{
	int		count_cols;
	char	*new_line;
	char	*symbols;

	symbols = "ABCB BCBA";
	new_line = "\n";
	count_cols = 1;
	write(1, &symbols[3 * r], 1);
	if (x > 1)
	{
		while (count_cols <= (x - 2))
		{
			write(1, &symbols[3 * r + 1], 1);
			count_cols++;
		}
		write(1, &symbols[3 * r + 2], 1);
	}
	write(1, new_line, 1);
}
