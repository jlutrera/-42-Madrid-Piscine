/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:36:40 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/24 18:44:11 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	get_nb(int *nb, int *suf, char *str)
{
	int		i;
	int		j;

	i = 0;
	*nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i >= 4)
	{
		j = -1;
		if ((i - 1) % 3 != 0)
			return (0);
		while (++j < i)
			if ((j == 0 && str[j] != '1') || (j != 0 && str[j] != '0'))
				return (0);
		*nb = i / 3;
		*suf = 1;
	}
	else
		*suf = 0;
	return (1);
}

char	*ft_check_space(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
			j++;
		else if (str[i - 1] != ' ')
			j++;
	}
	str2 = malloc (sizeof(char) * (j + 1));
	if (str2 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != ' ' || str[i - 1] != ' ')
			str2[j++] = str[i];
	}
	str2[j] = '\0';
	return (str2);
}

int	test_line(char *str, int *i)
{
	int		j;

	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] != ':')
		return (0);
	(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	j = *i;
	while (str[++j])
		if (str[j] <= 31 || str[j] >= 127)
			return (0);
	return (1);
}

int	parse_dict(t_dict *begin, char *str)
{
	int		nb;
	int		i;
	int		suf;
	char	*str2;

	if (get_nb(&nb, &suf, str) == 0)
		return (0);
	if (nb != 0)
	{
		i = 0;
		if (test_line(str, &i) == 0)
			return (0);
		str2 = ft_strdup(str + i);
		if (str2 == NULL)
			return (0);
		str2 = ft_check_space(str2);
		if (str2 == NULL)
			return (0);
		if (ft_push_data(begin, nb, suf, str2) == 0)
			return (0);
		return (1);
	}
	return (0);
}
