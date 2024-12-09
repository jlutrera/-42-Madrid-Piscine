/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <jutrera-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:33:26 by jutrera-          #+#    #+#             */
/*   Updated: 2024/12/09 12:33:26 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len++] != '\0');
	return len;
}

char *ft_itoa(int num)
{
	char	*str;
	int 	i;
	int 	j;
	char 	temp;

    str = malloc(35);
    if (!str)
		return NULL; 
    i = 0;
    while (num > 0)
	{
        str[i++] = num % 10 + '0';
        num /= 10;
    }
    str[i] = '\0';
    j = -1;
	while (++j < i / 2)
	{
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
	}
    return str;
}

int ft_atoi(char *str)
{
    int	num;
    int	i;

	i = 0;
	num = 0;
    while (str[i] >= '0' && str[i] <= '9') 
	{
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

int ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
	return 1;
}
