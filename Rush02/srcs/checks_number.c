/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:31:53 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/24 17:45:51 by ecoca-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	check_suff(int j, t_dict *begin_list)
{
	while (*begin_list->nb != -1
		&& (*begin_list->suf == 0 || j != *begin_list->nb))
		begin_list++;
	if (*begin_list->nb == -1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	check_nb(int nb, t_dict *begin_list)
{
	while (*begin_list->nb != -1
		&& (*begin_list->suf == 1 || nb != *begin_list->nb))
		begin_list++;
	if (*begin_list->nb == -1)
		return (0);
	return (1);
}

int	check_length(char *nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nbr[j] == '0')
		j++;
	while (nbr[i + j])
	{
		i++;
	}
	return (i);
}

void	check_and(int nb, int i, char *nbr)
{
	int	j;

	j = 0;
	if (nb != 0)
	{
		while (nbr[j] == '0' && j < i)
			j++;
		if ((i - j) > 2 && (nb % 100 != 0) && check_length(nbr) > 2
			&& (nb / 100 >= 1 || i == check_length(nbr)))
			ft_putstr("and ");
	}
}
