/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_custom_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:38:40 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/28 15:40:38 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
}

char	*ft_get_strerr(int errnum)
{
	extern const char *const	sys_errlist[];	
	extern int const			sys_nerr;	

	if (errnum < 0)
		errnum = -errnum;
	if (errnum < sys_nerr)
		return ((char *)sys_errlist[errnum]);
	return ("Unknown error");
}

void	ft_display_custom_error(int eno, char *argv)
{
	ft_putstr("ft_cat");
	ft_putstr(": ");
	ft_putstr(argv);
	ft_putstr(": ");
	ft_putstr(ft_get_strerr(eno));
	write(1, "\n", 1);
}
