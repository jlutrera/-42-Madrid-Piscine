/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:58:31 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/24 18:03:10 by ecoca-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	ft_push_data(t_dict *begin, int n, int suf, char *lit)
{
	t_dict	*push;

	push = begin;
	while (*push.nb != -1)
		push++;
	*push.nb = n;
	*push.suf = suf;
	*push.literal = ft_strdup(lit);
	return (1);
}
