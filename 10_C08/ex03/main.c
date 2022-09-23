/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:53:58 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/22 17:04:53 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 420;
	point->y = 291;
}

int main(void)
{
	t_point	point;

	set_point(&point);
	printf("x = %d, y = %d \n", point.x, point.y);
	return(0);
}
