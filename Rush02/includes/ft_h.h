/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:01:07 by ybayart           #+#    #+#             */
/*   Updated: 2022/07/24 18:33:44 by jutrera-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_dict
{
	int		nb;
	int		suf;
	char	*literal[50];
}	t_dict;

char	*ft_strdup(char *src);
int		ft_push_data(t_dict **liste, int n, int suf, char *lit);
int		ft_file_read(char *filepath, t_dict **begin);
int		ft_atoi(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		parse_dict(t_dict **begin, char *str);
int		check_number(char *nbr, t_dict *begin_list);
void	check_and(int nb, int i, char *nbr);
int		check_nb(int nb, t_dict *begin_list);
int		check_length(char *nbr);
int		check_suff(int j, t_dict *begin_list);
void	send_to_print(int nbr, t_dict *begin_list, int i, char *nbrc);
void	print_suff(int i, char *nbr, int j, t_dict *begin_list);

#endif
