/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:40:49 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/28 15:45:34 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_stdin(void)
{
	char	buffer;
	int		r;

	r = read(1, &buffer, 1);
	while (r != -1)
		r = read(1, &buffer, 1);
	if (r == -1)
		ft_putstr((char *)ft_get_strerr(errno));
}
