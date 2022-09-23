/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutrera- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:57:40 by jutrera-          #+#    #+#             */
/*   Updated: 2022/07/20 18:03:56 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	raiz;
	int	med;

	raiz = nb;
	med = 1;
	while ((raiz - med) > 0)
	{
		raiz = (raiz + med) / 2;
		med = nb / raiz;
	}
	if (raiz * raiz == nb)
		return (raiz);
	return (0);
}
