/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:51:00 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/12 15:41:26 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		flag;
	bool	c1;
	bool	c2;

	flag = 1;
	i = 0;
	while ((str[i] != '\0') && (flag == 1))
	{
		c1 = (str[i] >= 'A' && str[i] <= 'Z');
		c2 = (str[i] >= 'a' && str[i] <= 'z');
		if (c1 || c2)
			i++;
		else
			flag = 0;
	}
	return (flag);
}
