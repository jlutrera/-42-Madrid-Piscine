/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:32:51 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/20 18:02:12 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	r;

	if (nb < 0)
		return (0);
	else
	{
		if (nb == 0 || nb == 1)
			return (1);
		else
			r = nb * ft_iterative_factorial(nb - 1);
	}
	return (r);
}
