/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 21:16:06 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/28 13:24:13 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{	
	int	i;

	if (argc == 1)
		ft_stdin();
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				ft_stdin();
			else
				ft_cat(argv[i]);
			i++;
		}
	}
	return (0);
}
