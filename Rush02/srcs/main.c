/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:36:55 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/24 17:59:58 by ecoca-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	ft_checkerror(int argc, char **argv, char *nb, char *dictpath)
{
	int	i;

	if (argc == 2)
	{
		*dictpath = "dicts/numbers.dict";
		*nb = argv[1];
	}
	else if (argc == 3)
	{
		*dictpath = argv[1];
		*nb = argv[2];
	}
	else
		return (0);
	i = 0;
	while (nb[i] != '\0')
	{
		if (nb[i] < '0' || nb[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_init_dict(t_dict *dict)
{
	i = 0;
	while (i < 1000)
	{
		dict[i].nb = -1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_dict	*dict;
	char	*nb;
	char	*dictpath;
	int		code_error;

	code_error = ft_checkerror(argc, argv, &nb, &dictpath);
	if (code_error == 0)
		ft_putstr("Error\n");
	else
	{
		dict = malloc (1000 * sizeof(*t_dict));
		if (dict)
		{
			ft_init_dict(dict);
			if (ft_file_read(dictpath, dict) == 0)
				ft_putstr("Dict Error \n");
			else
				check_number(nb, dict);
		}
	}
	return (0);
}
